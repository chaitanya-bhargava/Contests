package main

import (
	"fmt"
	"os"
	"strings"
)

func day15_part1(lines []string) {
    var res int64 = 0
    grid := make([][]byte,0)
	i:=0
	for ; i<50; i++ {
		grid = append(grid, []byte(lines[i]))
	}
	x := 0
	y := 0
	for k:=0; k<len(grid); k++ {
		for l:=0; l<len(grid[k]); l++ {
			if grid[k][l] == '@' {
				x = k
				y = l
			}
		}
	}

	for ; i<len(lines); i++ {
		for _,ch := range lines[i] {
			switch ch {
			case '>':
				if grid[x][y+1]=='.' {
					grid[x][y]='.'
					y++
				} else if grid[x][y+1]=='O' {
					tempy := y+1
					for grid[x][tempy]=='O' {
						tempy++
					}
					if grid[x][tempy]=='.' {
						grid[x][tempy]='O'
						grid[x][y]='.'
						y++
						grid[x][y]='.'
					}
				}
			case '^':
				if grid[x-1][y]=='.' {
					grid[x][y]='.'
					x--
				} else if grid[x-1][y]=='O' {
					tempx := x-1
					for grid[tempx][y]=='O' {
						tempx--
					}
					if grid[tempx][y]=='.' {
						grid[tempx][y]='O'
						grid[x][y]='.'
						x--
						grid[x][y]='.'
					}
				}
			case '<':
				if grid[x][y-1]=='.' {
					grid[x][y]='.'
					y--
				} else if grid[x][y-1]=='O' {
					tempy := y-1
					for grid[x][tempy]=='O' {
						tempy--
					}
					if grid[x][tempy]=='.' {
						grid[x][tempy]='O'
						grid[x][y]='.'
						y--
						grid[x][y]='.'
					}
				}
			case 'v':
				if grid[x+1][y]=='.' {
					grid[x][y]='.'
					x++
				} else if grid[x+1][y]=='O' {
					tempx := x+1
					for grid[tempx][y]=='O' {
						tempx++
					}
					if grid[tempx][y]=='.' {
						grid[tempx][y]='O'
						grid[x][y]='.'
						x++
						grid[x][y]='.'
					}
				}
			}
		}
	}
	for i:= 0; i<len(grid); i++ {
		for j:=0; j<len(grid[i]); j++ {
			if grid[i][j]=='O' {
				res+=int64(100*i+j)
			}
		}
	}
    fmt.Print(res)
}

func canMoveBoxUp(grid [][]byte,i int,j int) bool{
    if grid[i-1][j]=='#' || grid[i-1][j+1]=='#' {
        return false
    }
    if grid[i-1][j]=='[' {
        return canMoveBoxUp(grid,i-1,j)
    }
    flag:=true
    if grid[i-1][j+1]=='[' {
        flag=flag && canMoveBoxUp(grid,i-1,j+1)
    }
    if grid[i-1][j]==']' {
        flag=flag && canMoveBoxUp(grid,i-1,j-1)
    }
    return flag
}

func canMoveBoxDown(grid [][]byte,i int,j int) bool{
    if grid[i+1][j]=='#' || grid[i+1][j+1]=='#' {
        return false
    }
    if grid[i+1][j]=='[' {
        return canMoveBoxDown(grid,i+1,j)
    }
    flag:=true
    if grid[i+1][j+1]=='[' {
        flag=flag && canMoveBoxDown(grid,i+1,j+1)
    }
    if grid[i+1][j]==']' {
        flag=flag && canMoveBoxDown(grid,i+1,j-1)
    }
    return flag
}

func moveBoxUp(grid [][]byte,i int,j int){
    if grid[i-1][j]=='#' || grid[i-1][j+1]=='#' {
        return
    }
    if grid[i-1][j]=='[' {
        moveBoxUp(grid,i-1,j)
        if grid[i-1][j]=='.' && grid[i-1][j+1]=='.' {
            grid[i][j]='.'
            grid[i][j+1]='.'
            grid[i-1][j]='['
            grid[i-1][j+1]=']'
        }
    }
    if grid[i-1][j+1]=='[' {
        moveBoxUp(grid,i-1,j+1)
    }
    if grid[i-1][j]==']' {
        moveBoxUp(grid,i-1,j-1)
    }
    if grid[i-1][j]=='.' && grid[i-1][j+1]=='.' {
        grid[i][j]='.'
        grid[i][j+1]='.'
        grid[i-1][j]='['
        grid[i-1][j+1]=']'
    }
}

func moveBoxDown(grid [][]byte,i int,j int){
    if grid[i+1][j]=='#' || grid[i+1][j+1]=='#' {
        return
    }
    if grid[i+1][j]=='[' {
        moveBoxDown(grid,i+1,j)
        if grid[i+1][j]=='.' && grid[i+1][j+1]=='.' {
            grid[i][j]='.'
            grid[i][j+1]='.'
            grid[i+1][j]='['
            grid[i+1][j+1]=']'
        }
    }
    if grid[i+1][j+1]=='[' {
        moveBoxDown(grid,i+1,j+1)
    }
    if grid[i+1][j]==']' {
        moveBoxDown(grid,i+1,j-1)
    }
    if grid[i+1][j]=='.' && grid[i+1][j+1]=='.' {
        grid[i][j]='.'
        grid[i][j+1]='.'
        grid[i+1][j]='['
        grid[i+1][j+1]=']'
    }
}

func day15_part2(lines []string) {
	var res int64 = 0
    grid1 := make([][]byte,0)
    grid := make([][]byte,0)
	i:=0
	for ; i<50; i++ {
		grid1 = append(grid1, []byte(lines[i]))
	}

	for k:=0; k<len(grid1); k++ {
        var row []byte = []byte("")
        for l:=0; l<len(grid1[k]); l++ {
            switch grid1[k][l] {
            case '#':
				row = append(row, []byte("##")...)
            case '.':
                row = append(row, []byte("..")...)
            case 'O':
                row = append(row, []byte("[]")...)
            case '@':
                row = append(row, []byte("@.")...)
            }
        }
        grid = append(grid, row)
    }

	x := 0
	y := 0
	for k:=0; k<len(grid); k++ {
		for l:=0; l<len(grid[k]); l++ {
			if grid[k][l] == '@' {
				x = k
				y = l
			}
		}
	}

	for ; i<len(lines); i++ {
		for _,ch := range lines[i] {
			switch ch {
			case '>':
				if grid[x][y+1]=='.' {
					grid[x][y]='.'
					y++
				} else if grid[x][y+1]=='[' {
					tempy := y+1
					for grid[x][tempy]=='[' || grid[x][tempy]==']' {
						tempy++
					}
					if grid[x][tempy]=='.' {
						for tempy!=y+1 {
                            grid[x][tempy]=grid[x][tempy-1];
                            tempy--;
                        }
						grid[x][y]='.'
						y++
						grid[x][y]='.'
					}
				}
			case '^':
				if grid[x-1][y]=='.' {
                    grid[x][y]='.'
                    x--
                } else if grid[x-1][y]=='[' {
                    if canMoveBoxUp(grid,x-1,y) {
                        moveBoxUp(grid,x-1,y)
                        if grid[x-1][y]=='.' {
                            grid[x][y]='.'
                            x--
                        }
                    }
                } else if grid[x-1][y]==']' {
                    if canMoveBoxUp(grid,x-1,y-1) {
                        moveBoxUp(grid,x-1,y-1)
                        if grid[x-1][y]=='.' {
                            grid[x][y]='.'
                            x--
                        }
                    }
                }
			case '<':
				if grid[x][y-1]=='.' {
					grid[x][y]='.'
					y--
				} else if grid[x][y-1]==']' {
					tempy := y-1
					for grid[x][tempy]==']' || grid[x][tempy]=='[' {
						tempy--
					}
					if grid[x][tempy]=='.' {
						for tempy!=y-1 {
                            grid[x][tempy]=grid[x][tempy+1];
                            tempy++;
                        }
						grid[x][y]='.'
						y--
						grid[x][y]='.'
					}
				}
			case 'v':
				if grid[x+1][y]=='.' {
                    grid[x][y]='.'
                    x++
                } else if grid[x+1][y]=='[' {
                    if canMoveBoxDown(grid,x+1,y) {
                        moveBoxDown(grid,x+1,y)
                        if grid[x+1][y]=='.' {
                            grid[x][y]='.'
                            x++
                        }
                    }
                } else if grid[x+1][y]==']' {
                    if canMoveBoxDown(grid,x+1,y-1) {
                        moveBoxDown(grid,x+1,y-1)
                        if grid[x+1][y]=='.' {
                            grid[x][y]='.'
                            x++
                        }
                    }
                }
			}
		}
	}
	for i:= 0; i<len(grid); i++ {
		for j:=0; j<len(grid[i]); j++ {
			if grid[i][j]=='[' {
				res+=int64(100*i+j)
			}
		}
	}
    fmt.Print(res)
}

func Day15() {
    data, _ := os.ReadFile("input.txt")
    lines := strings.Fields(string(data))
    fmt.Println("Part 1:")
    day15_part1(lines)
    fmt.Println("\nPart 2:")
    day15_part2(lines)
}