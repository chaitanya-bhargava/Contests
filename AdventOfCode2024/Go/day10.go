package main

import (
	"fmt"
	"os"
	"strings"
)

type day10_Coord struct {
	x, y int
}

var dx = []int{0, 1, 0, -1}
var dy = []int{1, 0, -1, 0}

func day10_dfs1(coord day10_Coord,grid []string,set map[day10_Coord]bool) {
	if grid[coord.x][coord.y] == '9' {
		set[coord] = true
	}
	for i := 0; i < 4; i++ {
		nx := coord.x + dx[i]
		ny := coord.y + dy[i]
		if nx >= 0 && nx < len(grid) && ny >= 0 && ny < len(grid[nx]) && grid[nx][ny] == grid[coord.x][coord.y] + 1 {
			day10_dfs1(day10_Coord{nx,ny},grid,set)
		}
	}
}

func day10_dfs2(coord day10_Coord,grid []string) int64 {
	if grid[coord.x][coord.y] == '9' {
		return 1
	}
	var ans int64 = 0
	for i := 0; i < 4; i++ {
		nx := coord.x + dx[i]
		ny := coord.y + dy[i]
		if nx >= 0 && nx < len(grid) && ny >= 0 && ny < len(grid[nx]) && grid[nx][ny] == grid[coord.x][coord.y] + 1 {
			ans+=day10_dfs2(day10_Coord{nx,ny},grid)
		}
	}
	return ans
}

func day10_part1(grid []string) {
	var res int64 = 0
	
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '0' {
				set := make(map[day10_Coord]bool)
				day10_dfs1(day10_Coord{i,j},grid,set)
				res+=int64(len(set))
			}
		}
	}
	fmt.Print(res)
}

func day10_part2(grid []string) {
    var res int64 = 0
	
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '0' {
				res+=day10_dfs2(day10_Coord{i,j},grid)
			}
		}
	}
	fmt.Print(res)
}

func Day10() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Fields(string(data))
	fmt.Println("Part 1:")
	day10_part1(lines)
	fmt.Println("\nPart 2:")
	day10_part2(lines)
}