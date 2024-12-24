package main

import (
	"fmt"
	"os"
	"strings"
)

func day19_helper(match string,mp map[string]bool,i int,dp *[]int) int {
    if i==len(match) {
		return 1
	}
    if (*dp)[i]!=-1 {
		return (*dp)[i]
	}
    ans := 0
    for j:=1; j+i<=len(match);j++ {
        if mp[match[i:i+j]] {
            ans+=day19_helper(match,mp,i+j,dp)
        }
    }
	(*dp)[i] = ans
    return ans
}

func day19_part1(lines []string) {
	res := 0
	patterns := strings.Split(lines[0],", ")
	mp := make(map[string]bool)
	for _,v:= range patterns  {
		mp[strings.TrimSpace(v)] = true
	}
	for i:=2; i<len(lines); i++ {
		dp := make([]int,len(lines[i]))
		for j:= range dp {
			dp[j] = -1
		}
		if day19_helper(strings.TrimSpace(lines[i]),mp,0,&dp)>0 {
			res++
		}
	}
    fmt.Print(res)
}

func day19_part2(lines []string) {
	res := 0
	patterns := strings.Split(lines[0],", ")
	mp := make(map[string]bool)
	for _,v:= range patterns  {
		mp[strings.TrimSpace(v)] = true
	}
	for i:=2; i<len(lines); i++ {
		dp := make([]int,len(lines[i]))
		for j:= range dp {
			dp[j] = -1
		}
		res+=day19_helper(strings.TrimSpace(lines[i]),mp,0,&dp)
	}
    fmt.Print(res)
}

func Day19() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day19_part1(lines)
	fmt.Println("\nPart 2:")
	day19_part2(lines)
}