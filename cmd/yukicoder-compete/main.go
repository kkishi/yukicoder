package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"os/exec"
	"path"
	"strconv"
	"time"
)

const (
	contestDir = "contests"
	problemDir = "problems"
)

type Contest struct {
	Id            int
	Name          string
	Date          time.Time
	ProblemIdList []int
}

type Problem struct {
	No int
}

func getContestList(phase string) ([]Contest, error) {
	resp, err := http.Get("http://yukicoder.me/api/v1/contest/" + phase)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	var cl []Contest
	if err := decoder.Decode(&cl); err != nil {
		return nil, err
	}
	return cl, nil
}

func printUpcomingContests() error {
	cs, err := getContestList("future")
	if err != nil {
		return err
	}
	for _, c := range cs {
		fmt.Println(c.Id, c.Date, c.Name)
	}
	return nil
}

func getContest(contestID int) (Contest, error) {
	resp, err := http.Get(fmt.Sprintf("http://yukicoder.me/api/v1/contest/id/%d", contestID))
	if err != nil {
		return Contest{}, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	c := Contest{}
	if err := decoder.Decode(&c); err != nil {
		return Contest{}, err
	}
	if c.Id == 0 {
		return Contest{}, fmt.Errorf("contest %d not found", contestID)
	}
	return c, nil
}

func getProblem(problemID int) (Problem, error) {
	resp, err := http.Get(fmt.Sprintf("http://yukicoder.me/api/v1/problems/%d", problemID))
	if err != nil {
		return Problem{}, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	p := Problem{}
	if err := decoder.Decode(&p); err != nil {
		return Problem{}, err
	}
	if p.No == 0 {
		return Problem{}, fmt.Errorf("problem %d not found", problemID)
	}
	return p, nil

}

func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

var tmpl = `#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
}`

func createDirs(c Contest) error {
	cdir := path.Join(contestDir, fmt.Sprintf("%d", c.Id))
	if err := os.MkdirAll(cdir, 0750); err != nil && !os.IsExist(err) {
		return err
	}
	for i, pid := range c.ProblemIdList {
		p, err := getProblem(pid)
		if err != nil {
			return err
		}
		pdir := path.Join(problemDir, "no", fmt.Sprintf("%d", p.No))
		if err := os.MkdirAll(pdir, 0750); err != nil && !os.IsExist(err) {
			return err
		}
		mainCC := path.Join(pdir, "main.cc")
		if e, err := exists(mainCC); err != nil {
			return err
		} else if !e {
			if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
				return err
			}
		}
		symLink := path.Join(cdir, (string)([]byte{byte('a' + i)}))
		if e, err := exists(symLink); err != nil {
			return err
		} else if !e {
			if err := os.Symlink(path.Join("..", "..", pdir), symLink); err != nil {
				return err
			}
		}
	}
	return nil
}

func downloadSamples(c Contest) error {
	for _, pid := range c.ProblemIdList {
		p, err := getProblem(pid)
		if err != nil {
			return err
		}
		dir := path.Join(problemDir, "no", fmt.Sprintf("%d", p.No))
		testDir := path.Join(dir, "test")
		if e, err := exists(testDir); err != nil {
			return err
		} else if e {
			fmt.Printf("%s already exists; skip\n", testDir)
			continue
		}
		url := fmt.Sprintf("https://yukicoder.me/problems/no/%d", p.No)
		cmd := exec.Command("oj", "d", url)
		cmd.Dir = dir
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Run(); err != nil {
			return err
		}
	}
	return nil
}

func compete(contestIDStr string) error {
	contestID, err := strconv.Atoi(contestIDStr)
	if err != nil {
		return err
	}

	c, err := getContest(contestID)
	if err != nil {
		return err
	}

	fmt.Println(c.Name)
	if d := c.Date.Sub(time.Now()); d > 0 {
		fmt.Println("Starts in", d)
		timer := time.NewTimer(d + 5*time.Second)
		<-timer.C
	}

	if err := createDirs(c); err != nil {
		return err
	}
	return downloadSamples(c)
}

func run() error {
	if len(flag.Args()) == 0 {
		fmt.Println("No contest ID is provided, printing upcoming contests.")
		if err := printUpcomingContests(); err != nil {
			return err
		}
		return nil
	}
	return compete(flag.Arg(0))
}

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}
