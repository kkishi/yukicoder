package main

import (
	"fmt"
	"os"
	"os/exec"
)

func main() {
	if len(os.Args) == 1 {
		fmt.Fprintln(os.Stderr, "Usage: yukicoder <command> [arguments]")
		os.Exit(2)
	}
	subcommand := os.Args[1]
	cmd := exec.Command("yukicoder-"+subcommand, os.Args[2:]...)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	if err := cmd.Run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
