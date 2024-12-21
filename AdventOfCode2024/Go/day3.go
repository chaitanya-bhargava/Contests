package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func day3_parse(comp string, ind int) int {
    a := ""
    i := ind
    for i < len(comp) && comp[i] >= '0' && comp[i] <= '9' {
        a += string(comp[i])
        i++
    }
    if i >= len(comp) || comp[i] != ',' {
        return 0
    }
    i++ 
    
    b := ""
    for i < len(comp) && comp[i] >= '0' && comp[i] <= '9' {
        b += string(comp[i])
        i++
    }
    if i >= len(comp) || comp[i] != ')' {
        return 0
    }
    
    aVal, _ := strconv.Atoi(a)
    bVal, _ := strconv.Atoi(b)
    return aVal * bVal
}

func day3_part1(lines []string) {
	res := 0
	comp := ""
    for _, line := range lines {
        comp+=line
    }
	ind := strings.Index(comp,"mul(")
	for ind!=-1 {
		res+=day3_parse(comp,ind+4)
		temp := strings.Index(comp[ind+1:],"mul(")
		if temp == -1 {
			break
		}
		ind = ind+1+temp
	}
    fmt.Print(res)
}

func day3_part2(lines []string) {
    res := 0
	comp := ""
    for _, line := range lines {
        comp+=line
    }
	enabled := true
	ind := strings.Index(comp,"mul(")
	for ind!=-1 {
		do_ind := strings.LastIndex(comp[:ind],"do()")
		dont_ind := strings.LastIndex(comp[:ind],"don't()")
		if(do_ind==-1 && dont_ind!=-1){
			enabled = false
		}
		if(do_ind!=-1 && dont_ind==-1){
			enabled = true
		}
		if(do_ind!=-1 && dont_ind!=-1){
			if(do_ind>dont_ind){
				enabled = true
			}else{
				enabled = false
			}
		}
		if(enabled){		
			res+=day3_parse(comp,ind+4)
		}
		temp := strings.Index(comp[ind+1:],"mul(")
		if temp == -1 {
			break
		}
		ind = ind+1+temp
	}
    fmt.Print(res)
}

func Day3() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")

	fmt.Println("Part 1:")
	day3_part1(lines)
	fmt.Println("\nPart 2:")
	day3_part2(lines)
}