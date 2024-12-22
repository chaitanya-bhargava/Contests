package main

import (
	"fmt"
	"os"
	"strings"
)

type Coord struct {
	x int
	y int
}

func day8_part1(grid []string) {
	res := 0
	mp := make(map[byte][]Coord)
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] != '.' {
				coord := Coord{i, j}
				mp[grid[i][j]] = append(mp[grid[i][j]], coord)
			}
		}
	}
	set := make(map[Coord]bool)
	for _, v := range mp {
		for i := 0; i < len(v); i++ {
			for j := i + 1; j < len(v); j++ {
				x1, y1 := v[i].x, v[i].y
				x2, y2 := v[j].x, v[j].y
				antix1 := 2*x1 - x2
				antix2 := 2*x2 - x1
				antiy1 := 2*y1 - y2
				antiy2 := 2*y2 - y1
				if antix1 >=0 && antix1 < len(grid) && antiy1 >=0 && antiy1 < len(grid[0]) {
					set[Coord{antix1, antiy1}] = true
				}
				if antix2 >=0 && antix2 < len(grid) && antiy2 >=0 && antiy2 < len(grid[0]) {
					set[Coord{antix2, antiy2}] = true
				}
			}
		}
	}
	
	res = len(set)
	fmt.Print(res)
}

func day8_part2(grid []string) {
    res := 0
    mp := make(map[byte][]Coord)
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] != '.' {
				coord := Coord{i, j}
				mp[grid[i][j]] = append(mp[grid[i][j]], coord)
			}
		}
	}
	set := make(map[Coord]bool)
	for _, v := range mp {
		for i := 0; i < len(v); i++ {
			for j := i + 1; j < len(v); j++ {
				x1, y1 := v[i].x, v[i].y
				x2, y2 := v[j].x, v[j].y
				set[Coord{x1, y1}] = true
				set[Coord{x2, y2}] = true
				k := 1
				antix1 := x1 - k*(x2 - x1)
				antiy1 := y1 - k*(y2 - y1)

				for antix1 >=0 && antix1 < len(grid) && antiy1 >=0 && antiy1 < len(grid[0]) {
					set[Coord{antix1, antiy1}] = true
					k++
					antix1 = x1 - k*(x2 - x1)
					antiy1 = y1 - k*(y2 - y1)
				}
				k = 1
				antix2 := x2 + k*(x2 - x1)
				antiy2 := y2 + k*(y2 - y1)

				for antix2 >=0 && antix2 < len(grid) && antiy2 >=0 && antiy2 < len(grid[0]) {
					set[Coord{antix2, antiy2}] = true
					k++
					antix2 = x2 + k*(x2 - x1)
					antiy2 = y2 + k*(y2 - y1)
				}
			}
		}
	}
	res = len(set)
    fmt.Print(res)
}

func Day8() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Fields(string(data))
	fmt.Println("Part 1:")
	day8_part1(lines)
	fmt.Println("\nPart 2:")
	day8_part2(lines)
}