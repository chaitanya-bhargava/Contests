package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func day7_parser1(nums []int64,target int64, i int64, curr int64) bool {
	if(i == int64(len(nums))) {
		return curr==target
	}
	if(curr>target){
		return false
	}
	return day7_parser1(nums, target, i+1,curr+nums[i]) || day7_parser1(nums, target, i+1,curr*nums[i])
}

type State struct {
    index int64
    curr  int64
}

func day7_parser2(nums []int64, target int64, i int64, curr int64, memo map[State]bool) bool {
    if curr > target {
        return false
    }
    if i == int64(len(nums)) {
        return curr == target
    }
    
    state := State{i, curr}
    if val, exists := memo[state]; exists {
        return val
    }
    
    concat, _ := strconv.ParseInt(strconv.FormatInt(curr,10) + strconv.FormatInt(nums[i],10), 10, 64)
    
    result := day7_parser2(nums, target, i+1, curr+nums[i], memo) || 
              day7_parser2(nums, target, i+1, curr*nums[i], memo) || 
			  day7_parser2(nums, target, i+1, concat, memo)    
    memo[state] = result
    return result
}

func day7_part1(lines []string) {
	res := 0
	for _, line := range lines {
		nums_temp := strings.Fields(line)
		nums := make([]int64, len(nums_temp))
		ans, _ := strconv.Atoi(nums_temp[0][:len(nums_temp[0])-1])
		for _, num := range nums_temp {
			val , _ := strconv.Atoi(num)
			nums = append(nums, int64(val))
		}
		if day7_parser1(nums, int64(ans),2,0) {
			res+=ans
		}
	}
    fmt.Print(res)
}

func day7_part2(lines []string) {
    res := 0
    for _, line := range lines {
        nums_temp := strings.Fields(line)
        nums := make([]int64, len(nums_temp))
        ans, _ := strconv.Atoi(nums_temp[0][:len(nums_temp[0])-1])
        for _, num := range nums_temp {
            val, _ := strconv.Atoi(num)
            nums = append(nums, int64(val))
        }
        memo := make(map[State]bool)
        if day7_parser2(nums, int64(ans), 2, 0, memo) {
            res += ans
        }
    }
    fmt.Print(res)
}

func Day7() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day7_part1(lines)
	fmt.Println("\nPart 2:")
	day7_part2(lines)
}