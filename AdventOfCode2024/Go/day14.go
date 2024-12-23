package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func day14_part1(lines []string) {
    var res int64 = 0
    quad1 := 0
    quad2 := 0
    quad3 := 0
    quad4 := 0
	n:=101
	m:=103
	for i:=0; i < len(lines); i++ {
		x,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],"=")+1:strings.Index(lines[i],",")])) 
		y,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],",")+1:strings.Index(lines[i]," ")]))
		vx,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.LastIndex(lines[i],"=")+1:strings.LastIndex(lines[i],",")]))
		vy,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.LastIndex(lines[i],",")+1:]))
		nx := ((x+100*vx)%n+n)%n
		ny := ((y+100*vy)%m+m)%m
		if nx<(n/2) && ny<(m/2){
			quad1++
		}
        if nx>(n/2) && ny<(m/2){
			quad2++
		}
        if nx<(n/2) && ny>(m/2){
			quad3++
		} 
        if nx>(n/2) && ny>(m/2){
			quad4++
		}
	}
	res = int64(quad1 * quad2 * quad3 * quad4)
    fmt.Print(res)
}

func day14_part2(lines []string) {
	n:=103
	m:=101
	fo, err := os.Create("output.txt")
    if err != nil {
        panic(err)
    }
	for j:=1; j<10000; j++ {
		grid := make([][]byte,103)
		for i := range grid {
			grid[i]=make([]byte,101)
			for j := range grid[i] {
				grid[i][j]='.'
			}
		}
		for i:=0; i < len(lines); i++ {
			y,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],"=")+1:strings.Index(lines[i],",")])) 
			x,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.Index(lines[i],",")+1:strings.Index(lines[i]," ")]))
			vy,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.LastIndex(lines[i],"=")+1:strings.LastIndex(lines[i],",")]))
			vx,_ := strconv.Atoi(strings.TrimSpace(lines[i][strings.LastIndex(lines[i],",")+1:]))	
			nx := ((x+j*vx)%n+n)%n
			ny := ((y+j*vy)%m+m)%m
			grid[nx][ny]='#'
		}
		fo.Write([]byte("\n"))
		fo.Write([]byte(strconv.Itoa(j)))
		fo.Write([]byte("\n"))
		for k := range grid {
			fo.Write([]byte(grid[k]))
			fo.Write([]byte("\n"))
		}
	}
}

func Day14() {
    data, _ := os.ReadFile("input.txt")
    lines := strings.Split(string(data), "\n")
    fmt.Println("Part 1:")
    day14_part1(lines)
    fmt.Println("\nPart 2:")
    day14_part2(lines)
}