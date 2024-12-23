package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solveSystemOfEquations(system [][]float64) (float64, float64) {
	D := (system[0][0] * system[1][1]) - (system[1][0] * system[0][1])
	Dx := (system[0][2] * system[1][1]) - (system[1][2] * system[0][1])
	Dy := (system[0][0] * system[1][2]) - (system[1][0] * system[0][2])
	
	x := Dx / D
	y := Dy / D
	
	return x, y
}

func day13_part1(lines []string) {
    var res int64 = 0
    i := 0
	for i < len(lines)-3{
		plus_ind := strings.Index(lines[i],"+")
		comma_ind := strings.Index(lines[i],",")
		ax, _ := strconv.ParseFloat(strings.TrimSpace(lines[i][plus_ind+1:comma_ind]),64)
		plus_ind = strings.LastIndex(lines[i],"+")
		ay, _ := strconv.ParseFloat(strings.TrimSpace(lines[i][plus_ind+1:]),64)
		plus_ind = strings.Index(lines[i+1],"+")
		comma_ind = strings.Index(lines[i+1],",")
		bx, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+1][plus_ind+1:comma_ind]),64)
		plus_ind = strings.LastIndex(lines[i+1],"+")
		by, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+1][plus_ind+1:]),64)
		equal_ind := strings.Index(lines[i+2],"=")
		comma_ind = strings.Index(lines[i+2],",")
		px, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+2][equal_ind+1:comma_ind]),64)
		equal_ind = strings.LastIndex(lines[i+2],"=")
		py, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+2][equal_ind+1:]),64)
		// px+=10000000000000
        // py+=10000000000000
		A, B := solveSystemOfEquations([][]float64{{ax,bx,px},{ay,by,py}})
		if A==float64(uint64(A)) && B==float64(uint64(B)) {
			res+=int64(3*A+B)
		} 
		i+=4
	}
    fmt.Print(res)
}

func day13_part2(lines []string) {
    var res int64 = 0
    i := 0
	for i < len(lines)-3{
		plus_ind := strings.Index(lines[i],"+")
		comma_ind := strings.Index(lines[i],",")
		ax, _ := strconv.ParseFloat(strings.TrimSpace(lines[i][plus_ind+1:comma_ind]),64)
		plus_ind = strings.LastIndex(lines[i],"+")
		ay, _ := strconv.ParseFloat(strings.TrimSpace(lines[i][plus_ind+1:]),64)
		plus_ind = strings.Index(lines[i+1],"+")
		comma_ind = strings.Index(lines[i+1],",")
		bx, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+1][plus_ind+1:comma_ind]),64)
		plus_ind = strings.LastIndex(lines[i+1],"+")
		by, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+1][plus_ind+1:]),64)
		equal_ind := strings.Index(lines[i+2],"=")
		comma_ind = strings.Index(lines[i+2],",")
		px, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+2][equal_ind+1:comma_ind]),64)
		equal_ind = strings.LastIndex(lines[i+2],"=")
		py, _ := strconv.ParseFloat(strings.TrimSpace(lines[i+2][equal_ind+1:]),64)
		px+=10000000000000
        py+=10000000000000
		A, B := solveSystemOfEquations([][]float64{{ax,bx,px},{ay,by,py}})
		if A==float64(uint64(A)) && B==float64(uint64(B)) {
			res+=int64(3*A+B)
		} 
		i+=4
	}
    fmt.Print(res)
}

func Day13() {
    data, _ := os.ReadFile("input.txt")
    lines := strings.Split(string(data), "\n")
	lines = append(lines, "")
    fmt.Println("Part 1:")
    day13_part1(lines)
    fmt.Println("\nPart 2:")
    day13_part2(lines)
}