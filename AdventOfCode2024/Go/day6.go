package main

import (
	"fmt"
	"os"
	"strings"
)

func day6_part1(lines []string) {
	res := 0
	dir:=0
	dx:=[4]int{-1,0,1,0}
	dy:=[4]int{0,1,0,-1}
	grid := make([][]byte, len(lines))
	for i := range lines {
		grid[i] = []byte(lines[i])
	}
	x := 0
	y := 0
	flag := false
	for i:=0;i<len(grid);i++ {
		for j:=0;j<len(grid[i]);j++ {
			if grid[i][j] == '^'{
				x = i
				y = j
				flag = true
				break
			}
		}
		if flag{
			break
		}
	}
	for {
		grid[x][y] = 'X'
		newx := x+dx[dir]
		newy := y+dy[dir]
		if newx<0 || newx>=len(grid) || newy<0 || newy>=len(grid[0]){
			break
		}
		if grid[newx][newy] == '#'{
			dir = (dir+1)%4
		} else{
			x = newx
			y = newy
		}
	}
	for i:=0;i<len(grid);i++ {
		for j:=0;j<len(grid[i]);j++ {
			if grid[i][j] == 'X'{
				res++
			}
		}
	}
    fmt.Print(res)
}

func day6_part2(lines []string) {
    res := 0
	dx:=[4]int{-1,0,1,0}
	dy:=[4]int{0,1,0,-1}
	grid := make([][]byte, len(lines))
	for i := range lines {
		grid[i] = []byte(lines[i])
	}
	startx := 0
	starty := 0
	flag := false
	for i:=0;i<len(grid);i++ {
		for j:=0;j<len(grid[i]);j++ {
			if grid[i][j] == '^'{
				startx = i
				starty = j
				flag = true
				break
			}
		}
		if flag{
			break
		}
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '.' {
				grid[i][j] = '#'
				visited := make([][][]bool, len(grid))
				for i := range visited {	
					visited[i] = make([][]bool, len(grid[i]))
					for j := range visited[i] {
						visited[i][j] = make([]bool, 4)
					}
				}
				x := startx
				y := starty
				dir := 0
				visited [x][y][dir] = true
				flag := false
				for {
					newx := x+dx[dir]
					newy := y+dy[dir]
					if newx<0 || newx>=len(grid) || newy<0 || newy>=len(grid[0]){
						break
					}
					if grid[newx][newy] == '#'{
						dir = (dir+1)%4
					} else{
						x = newx
						y = newy
						if visited[x][y][dir] {
							flag = true
							break
						}
						visited[x][y][dir] = true
					}
				}
				if flag {
					res++
				}
				grid[i][j] = '.'
			}
		}
	}
    fmt.Print(res)
}

func Day6() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day6_part1(lines)
	fmt.Println("\nPart 2:")
	day6_part2(lines)
}