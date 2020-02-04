package main

import (
	"fmt"
	"os"
	"strconv"

	up "./unique_paths"
)

func main() {
	argM, argN := 3, 3
	if len(os.Args) > 2 {
		argM, _ = strconv.Atoi(os.Args[1])
		argN, _ = strconv.Atoi(os.Args[2])
	}
	fmt.Printf("No of paths for %v, %v are %v \n", argM, argN, up.UniquePaths(argM, argN))
}
