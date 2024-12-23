package main

import (
	"fmt"
	"os"
	"strings"
)

var corners map[[4]int]int
var day12_dx = []int{0, 0, 1, -1}
var day12_dy = []int{1, -1, 0, 0}

type Pair struct {
    first, second int64
}

type Position struct {
    x, y int
}

func bfs(grid []string, startI, startJ int, visited [][]int) Pair {
    n := len(grid)
    m := len(grid[0])
    if startI >= n || startJ >= m {
        return Pair{0, 0}
    }
    
    ch := grid[startI][startJ]
    q := make([]Position, 0)
    q = append(q, Position{startI, startJ})
    visited[startI][startJ] = 1
    ans := Pair{0, 0}
    
    for len(q) > 0 {
        x, y := q[0].x, q[0].y
        q = q[1:]
        ans.first++
        
        for k := 0; k < 4; k++ {
            newx := x + day12_dx[k]
            newy := y + day12_dy[k]
            if newx >= 0 && newy >= 0 && newx < n && newy < m {
                if grid[newx][newy] == ch && visited[newx][newy] == 0 {
                    q = append(q, Position{newx, newy})
                    visited[newx][newy] = 1
                }
            }
            if newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] != ch {
                ans.second++
            }
        }
    }
    return ans
}

func bfs2(grid []string, startI, startJ int, visited [][]int) Pair {
    ch := grid[startI][startJ]
    q := make([]Position, 0)
    q = append(q, Position{startI, startJ})
    visited[startI][startJ] = 1
    ans := Pair{0, 0}
    
    for len(q) > 0 {
        x, y := q[0].x, q[0].y
        q = q[1:]
        ans.first++
        dir := [4]int{0, 0, 0, 0}
        
        for k := 0; k < 4; k++ {
            newx := x + day12_dx[k]
            newy := y + day12_dy[k]
            if newx >= 0 && newy >= 0 && newx < len(grid) && newy < len(grid[0]) && grid[newx][newy] == ch {
                if  visited[newx][newy] == 0 {
                    q = append(q, Position{newx, newy})
                    visited[newx][newy] = 1
                }
                dir[k] = 1
            }
        }
        
        cornerState := corners[dir]
        if cornerState > 0 {
            ans.second += int64(cornerState)
        } else {
            switch cornerState {
            case -1:
                if x+1 < len(grid) && y+1 < len(grid[0]) && grid[x+1][y+1] != ch { ans.second++ }
                if x-1 >= 0 && y+1 < len(grid[0]) && grid[x-1][y+1] != ch { ans.second++ }
                if x+1 < len(grid) && y-1 >= 0 && grid[x+1][y-1] != ch { ans.second++ }
                if x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] != ch { ans.second++ }
            case -2:
                ans.second++
                if x+1 < len(grid) && y+1 < len(grid[0]) && grid[x+1][y+1] != ch { ans.second++ }
            case -3:
                ans.second++
                if x-1 >= 0 && y+1 < len(grid[0]) && grid[x-1][y+1] != ch { ans.second++ }
            case -4:
                ans.second++
                if x+1 < len(grid) && y-1 >= 0 && grid[x+1][y-1] != ch { ans.second++ }
            case -5:
                ans.second++
                if x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] != ch { ans.second++ }
            case -6:
                if x+1 < len(grid) && y-1 >= 0 && grid[x+1][y-1] != ch { ans.second++ }
                if x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] != ch { ans.second++ }
            case -7:
                if x+1 < len(grid) && y+1 < len(grid[0]) && grid[x+1][y+1] != ch { ans.second++ }
                if x-1 >= 0 && y+1 < len(grid[0]) && grid[x-1][y+1] != ch { ans.second++ }
            case -8:
                if x-1 >= 0 && y+1 < len(grid[0]) && grid[x-1][y+1] != ch { ans.second++ }
                if x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] != ch { ans.second++ }
            case -9:
                if x+1 < len(grid) && y+1 < len(grid[0]) && grid[x+1][y+1] != ch { ans.second++ }
                if x+1 < len(grid) && y-1 >= 0 && grid[x+1][y-1] != ch { ans.second++ }
            }
        }
    }
    return ans
}

func day12_part1(grid []string) {
    res := 0
    visited := make([][]int, len(grid))
	for i := 0; i < len(grid); i++ {
		visited[i] = make([]int, len(grid[i]))
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if visited[i][j] == 0 {
				p := bfs(grid, i, j, visited)
				res += int(p.first * p.second)
			}
		}
	}
    fmt.Print(res)
}

func day12_part2(grid []string) {
    res := 0
    corners = make(map[[4]int]int)
    corners[[4]int{0,0,0,0}] = 4
    corners[[4]int{1,1,1,1}] = -1
    corners[[4]int{0,0,0,1}] = 2
    corners[[4]int{0,0,1,0}] = 2
    corners[[4]int{0,1,0,0}] = 2
    corners[[4]int{1,0,0,0}] = 2
    corners[[4]int{1,1,0,0}] = 0
    corners[[4]int{0,0,1,1}] = 0
    corners[[4]int{1,0,1,0}] = -2
    corners[[4]int{1,0,0,1}] = -3
    corners[[4]int{0,1,1,0}] = -4
    corners[[4]int{0,1,0,1}] = -5
    corners[[4]int{0,1,1,1}] = -6
    corners[[4]int{1,0,1,1}] = -7
    corners[[4]int{1,1,0,1}] = -8
    corners[[4]int{1,1,1,0}] = -9

    visited := make([][]int, len(grid))
    for i := 0; i < len(grid); i++ {
        visited[i] = make([]int, len(grid[i]))
    }
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if visited[i][j] == 0 {
                temp := bfs2(grid, i, j, visited)
                res += int(temp.first * temp.second)
            }
        }
    }
    fmt.Print(res)
}

func Day12() {
    data, _ := os.ReadFile("input.txt")
    lines := strings.Fields(string(data))
    fmt.Println("Part 1:")
    day12_part1(lines)
    fmt.Println("\nPart 2:")
    day12_part2(lines)
}