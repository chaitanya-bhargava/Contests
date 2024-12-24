package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

var day18_dx = []int{0,-1,0,1}
var day18_dy = []int{1,0,-1,0}

func day18_part1(lines []string) {
	res := 0
	grid := make([][]byte,71)
	for i:= range grid {
		grid[i] = make([]byte,71)
		for j := range grid[i] {
			grid[i][j] = '.'
		}
	}
	for i:= 0; i<1024; i++ {
		y, _ := strconv.Atoi(strings.TrimSpace(lines[i][:strings.Index(lines[i],",")]))
		x, _ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],",")+1:]))
		grid[x][y]='#'
	}
	q := make([][]int,0)
    q = append(q, []int{0,0,0})
	visited := make([][]int, len(grid))
	for i:= range grid {
		visited[i] = make([]int,len(grid[0]))
	}
    visited[0][0]=1
    for len(q)>0 {
        x := q[0][0]
        y := q[0][1]
        steps := q[0][2]
		q = q[1:]
        if(x==len(grid)-1 && y==len(grid)-1) {
			res = steps
		}
        for i:=0; i<4; i++ {
            newx := x+day18_dx[i]
            newy := y+day18_dy[i]
            if newx>=0 && newy>=0 && newx<len(grid) && newy<len(grid[0]) && visited[newx][newy]==0 && grid[newx][newy]!='#' {
                q = append(q, []int{newx,newy,steps+1})
                visited[newx][newy]=1;
            }
        } 
    }
    fmt.Print(res)
}

func day18_part2(lines []string) {
	grid := make([][]byte,71)
	for i:= range grid {
		grid[i] = make([]byte,71)
		for j := range grid[i] {
			grid[i][j] = '.'
		}
	}
	for i:= 0; i<len(lines); i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(lines[i][:strings.Index(lines[i],",")]))
		y, _ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],",")+1:]))
		grid[x][y]='#'
		res := -1
		q := make([][]int,0)
		q = append(q, []int{0,0,0})
		visited := make([][]int, len(grid))
		for i:= range grid {
			visited[i] = make([]int,len(grid[0]))
		}
		visited[0][0]=1
		for len(q)>0 {
			x := q[0][0]
			y := q[0][1]
			steps := q[0][2]
			q = q[1:]
			if(x==len(grid)-1 && y==len(grid)-1) {
				res = steps
			}
			for i:=0; i<4; i++ {
				newx := x+day18_dx[i]
				newy := y+day18_dy[i]
				if newx>=0 && newy>=0 && newx<len(grid) && newy<len(grid[0]) && visited[newx][newy]==0 && grid[newx][newy]!='#' {
					q = append(q, []int{newx,newy,steps+1})
					visited[newx][newy]=1;
				}
			} 
		}
		if res == -1 {
			fmt.Printf("%d,%d",x,y)
			return
		}
	}
}

func Day18() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day18_part1(lines)
	fmt.Println("\nPart 2:")
	day18_part2(lines)
}