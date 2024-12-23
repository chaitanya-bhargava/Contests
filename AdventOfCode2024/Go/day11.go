package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func day11_blink(stones []int64) []int64 {
	sz := len(stones)
	for i := 0; i < sz; i++ {
		if stones[i] == 0 {
			stones[i] = 1
		} else {
			numStr := strconv.FormatInt(stones[i], 10)
			if len(numStr)%2 == 0 {
				mid := len(numStr) / 2
				first, _ := strconv.ParseInt(numStr[:mid], 10, 64)
				second, _ := strconv.ParseInt(numStr[mid:], 10, 64)
				stones[i] = first
				stones = append(stones, second)
			} else {
				stones[i] *= 2024
			}
		}
	}
	return stones
}

func day11_blink2(stones map[int]int) map[int]int {
	stones2 := make(map[int]int)
	for k, v := range stones {
		if k == 0 {
			stones2[1]+=v
		} else {
			numStr := strconv.Itoa(k)
			if len(numStr)%2 == 0 {
				mid := len(numStr) / 2
				first, _ := strconv.Atoi(numStr[:mid])
				second, _ := strconv.Atoi(numStr[mid:])
				stones2[first]+=v
				stones2[second]+=v
			} else {
				stones2[k*2024]+=v
			}
		}
	}
	return stones2
}


func day11_part1(lines []string) {
	res := 0
	temp := strings.Fields(lines[0])
	stones := make([]int64, 0)
	for i := 0; i < len(temp); i++ {
		num, _ := strconv.ParseInt(strings.TrimSpace(temp[i]), 10, 64)
		stones = append(stones, num)
	}
	for i := 0; i < 25; i++ {
		stones = day11_blink(stones)
	}
	res=len(stones)
	fmt.Print(res)
}

func day11_part2(lines []string) {
    res := 0
	temp := strings.Fields(lines[0])
	stones := make(map[int]int)
	for i := 0; i < len(temp); i++ {
		num, _ := strconv.ParseInt(strings.TrimSpace(temp[i]), 10, 64)
		stones[int(num)]++
	}
	for i := 0; i < 75; i++ {
		stones = day11_blink2(stones)
	}
	for _,v := range stones {
		res+=v
	}
	fmt.Print(res)
}

func Day11() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day11_part1(lines)
	fmt.Println("\nPart 2:")
	day11_part2(lines)
}