package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func day1_part1(lines []string) {
    var A, B []int
    
    for _, line := range lines {
        nums := strings.Fields(line)
        num1, _ := strconv.Atoi(nums[0])
        num2, _ := strconv.Atoi(nums[1])
        A = append(A, num1)
        B = append(B, num2)
    }
    
    sort.Ints(A)
    sort.Ints(B)

    res := 0
	for i := 0; i < len(A); i++ {
		res+=int(math.Abs(float64(A[i]-B[i])))
	}
	fmt.Print(res)
}

func day1_part2(lines []string) {
    var A, B []int
    
    for _, line := range lines {
        nums := strings.Fields(line)
        num1, _ := strconv.Atoi(nums[0])
        num2, _ := strconv.Atoi(nums[1])
        A = append(A, num1)
        B = append(B, num2)
    }
    
	mp := make(map[int]int)

	for i := 0; i < len(B); i++ {
		mp[B[i]]++	
	}

	res := 0
	for i := 0; i < len(A); i++ {
		res+=mp[A[i]]*A[i]
	}
	fmt.Print(res)
}

func Day1() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")

	fmt.Println("Part 1:")
	day1_part1(lines)
	fmt.Println("\nPart 2:")
	day1_part2(lines)
}