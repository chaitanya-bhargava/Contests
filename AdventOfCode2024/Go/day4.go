package main

import (
	"fmt"
	"os"
	"strings"
)

func day4_part1(grid []string) {
	res := 0
	xmas := "XMAS"
	dx := []int{1, 1, 0, -1, -1, -1, 0, 1}
	dy := []int{0, 1, 1, 1, 0, -1, -1, -1}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == xmas[0] {
				for k := 0; k < 8; k++ {
					valid := true
					for m := 1; m < 4 && valid; m++ {
						x, y := i+m*dx[k], j+m*dy[k]
						if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[i]) || grid[x][y] != xmas[m] {
							valid = false
						}
					}
					if valid {
						res++
					}
				}
			}
		}
	}
    fmt.Print(res)
}

func day4_part2(lines []string) {
    res := 0
	dx := []int{-1,-1,1,1}
	dy := []int{-1,1,1,-1}
	for i := 0; i < len(lines); i++ {
		for j := 0; j < len(lines[i]); j++ {
			if lines[i][j] == 'A' {
				for k := 0; k < 4; k++ {
					sx1, sy1 := i+dx[k], j+dy[k]
					sx2, sy2 := i+dx[(k+1)%4], j+dy[(k+1)%4]
					mx1, my1 := i+dx[(k+2)%4], j+dy[(k+2)%4]
					mx2, my2 := i+dx[(k+3)%4], j+dy[(k+3)%4]
					if sx1 >= 0 && sx1 < len(lines) && sy1 >= 0 && sy1 < len(lines[i]) && lines[sx1][sy1] == 'S' && 
					   sx2 >= 0 && sx2 < len(lines) && sy2 >= 0 && sy2 < len(lines[i]) && lines[sx2][sy2] == 'S' &&
					   mx1 >= 0 && mx1 < len(lines) && my1 >= 0 && my1 < len(lines[i]) && lines[mx1][my1] == 'M' &&
					   mx2 >= 0 && mx2 < len(lines) && my2 >= 0 && my2 < len(lines[i]) && lines[mx2][my2] == 'M' {
						res++
					}
				}
			}
		}
	}
    fmt.Print(res)
}

func Day4() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")

	fmt.Println("Part 1:")
	day4_part1(lines)
	fmt.Println("\nPart 2:")
	day4_part2(lines)
}