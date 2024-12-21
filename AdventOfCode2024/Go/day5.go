package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func day5_part1(lines []string) {
    res := 0
    grid := make(map[[2]int]int)
    i := 0
    for i < 1176 {
        nums := strings.Split(lines[i], "|")
        
        num1, _ := strconv.Atoi(strings.TrimSpace(nums[0]))
        num2, _ := strconv.Atoi(strings.TrimSpace(nums[1]))
        grid[[2]int{num1, num2}] = 1
        i++
    }
	i++;
	for i<len(lines) {
		flag := true
		strQuery := strings.Split(lines[i],",")
		query := make([]int, len(strQuery))
		for i, str := range strQuery {
			query[i], _ = strconv.Atoi(strings.TrimSpace(str))
		}
		for j:=0;j<len(query);j++ {
			for k:=j+1;k<len(query);k++ {
				if(grid[[2]int{query[k],query[j]}] == 1) {
					flag = false
					break
				}
			}
		}
		if flag {
			res+=query[len(query)/2]
		}
		i++
	}

    fmt.Print(res)
}

func day5_part2(lines []string) {
    res := 0
	grid := make(map[[2]int]int)
    i := 0
    for i < 1176 {
        nums := strings.Split(lines[i], "|")
        
        num1, _ := strconv.Atoi(strings.TrimSpace(nums[0]))
        num2, _ := strconv.Atoi(strings.TrimSpace(nums[1]))
        grid[[2]int{num1, num2}] = 1
        i++
    }
	i++;
	for i<len(lines) {
		strQuery := strings.Split(lines[i],",")
		query := make([]int, len(strQuery))
		for i, str := range strQuery {
			query[i], _ = strconv.Atoi(strings.TrimSpace(str))
		}
		flag := false
		for j:=0;j<len(query)-1;j++ {
			for k:=0;k<len(query)-j-1;k++ {
				if(grid[[2]int{query[k+1],query[k]}] == 1) {
					flag = true
					query[k+1], query[k] = query[k], query[k+1]
				}
			}
		}
		if flag {
			res+=query[len(query)/2]
		}
		i++
	}

    fmt.Print(res)
}

func Day5() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day5_part1(lines)
	fmt.Println("\nPart 2:")
	day5_part2(lines)
}