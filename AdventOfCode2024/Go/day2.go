package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func day2_part1(lines []string) {
    res := 0
    for _, line := range lines {
        strNums := strings.Fields(line)
        nums := make([]int, len(strNums))
        for i, n := range strNums {
            nums[i], _ = strconv.Atoi(n)
        }
        
        inc := true
        dec := true
        gap := true
        for i := 1; i < len(nums); i++ {
            if math.Abs(float64(nums[i]-nums[i-1])) < 1 || math.Abs(float64(nums[i]-nums[i-1])) > 3 {
                gap = false
            } 
            if nums[i] < nums[i-1] {
                inc = false
            }
            if nums[i] > nums[i-1] {
                dec = false
            }
        }
		if gap && (inc || dec) {
			res++
		}
    }
    fmt.Print(res)
}

func day2_part2(lines []string) {
    res := 0
    for _, line := range lines {
        strNums := strings.Fields(line)
        nums := make([]int, len(strNums))
        for i, n := range strNums {
            nums[i], _ = strconv.Atoi(n)
        }
        
		for skip := 0; skip < len(nums); skip++ {
			if skip == 0 {
				inc := true
				dec := true
				gap := true
				for i := 2; i < len(nums); i++ {
					if math.Abs(float64(nums[i]-nums[i-1])) < 1 || math.Abs(float64(nums[i]-nums[i-1])) > 3 {
						gap = false
					} 
					if nums[i] < nums[i-1] {
						inc = false
					}
					if nums[i] > nums[i-1] {
						dec = false
					}
				}
				if gap && (inc || dec) {
					res++
					break
				}
			} else if skip == len(nums)-1 {
				inc := true
				dec := true
				gap := true
				for i := 1; i < len(nums)-1; i++ {
					if math.Abs(float64(nums[i]-nums[i-1])) < 1 || math.Abs(float64(nums[i]-nums[i-1])) > 3 {
						gap = false
						} 
						if nums[i] < nums[i-1] {
							inc = false
						}
						if nums[i] > nums[i-1] {
							dec = false
						}
					}
					if gap && (inc || dec) {
						res++
						break
					}
			} else {
				inc := true
				dec := true
				gap := true
				left := 0 
				right := 1
				for right<len(nums) {
					if left == skip {
						left++
					}
					if right == skip {
						right++
				}
				if math.Abs(float64(nums[right]-nums[left])) < 1 || math.Abs(float64(nums[right]-nums[left])) > 3 {
					gap = false
					} 
					if nums[right] < nums[left] {
						inc = false
					}
					if nums[right] > nums[left] {
						dec = false
					}
					left++
					right++
				}
				if gap && (inc || dec) {
					res++
					break
				}
			}
		}
    }
    fmt.Print(res)
}

func Day2() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")

	fmt.Println("Part 1:")
	day2_part1(lines)
	fmt.Println("\nPart 2:")
	day2_part2(lines)
}