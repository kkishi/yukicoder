package main

import (
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"path"
	"regexp"
	"strconv"
)

const (
	problemDir = "problems"
)

var re = regexp.MustCompile("https://yukicoder.me/problems/no/(.+)")

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

func download(problemURL string) error {
	ms := re.FindStringSubmatch(problemURL)
	if len(ms) != 2 {
		return fmt.Errorf("invalid url: %s", problemURL)
	}
	contestID, err := strconv.Atoi(ms[1])
	if err != nil {
		return err
	}
	dir := path.Join(problemDir, "no", fmt.Sprintf("%d", contestID))
	if err := os.MkdirAll(dir, 0750); err != nil && !os.IsExist(err) {
		return err
	}
	mainCC := path.Join(dir, "main.cc")
	if e, err := exists(mainCC); err != nil {
		return err
	} else if !e {
		if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
			return err
		}
	}
	testDir := path.Join(dir, "test")
	if e, err := exists(testDir); err != nil {
		return err
	} else if e {
		fmt.Printf("%s already exists; skip\n", testDir)
		return nil
	}
	cmd := exec.Command("oj", "d", problemURL)
	cmd.Dir = dir
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func run() error {
	if len(flag.Args()) == 0 {
		return errors.New("no problem URL provided")
	}
	return download(flag.Arg(0))
}

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}
