package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)


func day17_part1(lines []string) {
	A,_ := strconv.ParseInt(strings.TrimSpace(lines[0][strings.Index(lines[0],": ")+2:]),10,64) 
	B,_ := strconv.ParseInt(strings.TrimSpace(lines[0][strings.Index(lines[1],": ")+2:]),10,64) 
	C,_ := strconv.ParseInt(strings.TrimSpace(lines[0][strings.Index(lines[2],": ")+2:]),10,64) 
	program := strings.Split(lines[4][strings.Index(lines[4],": ")+2:],",")
    inst := make([]int64,0)
    for _,v := range program {
		val, _ := strconv.Atoi(strings.TrimSpace(v))
		inst = append(inst, int64(val))
	}
	var i int64=0
	for i<int64(len(inst)) {
        temp:=inst[i+1];
        var op int64 = 0
        if temp<=3 {
			op=temp;
		} else if temp==4 {
			op=A;
		} else if temp==5 {
			op=B;
		} else if temp==6 {
			op=C;
		}
        switch (inst[i]) {
        case 0:
            A = A / int64(math.Pow(2, float64(op)))
            i+=2
        case 1:
            B=B^temp
            i+=2
        case 2:
            B=op%8
            i+=2
        case 3:
            if A!=0 {
                i=temp
            } else {
				i+=2
			}
        case 4:
            B=B^C
            i+=2
        case 5:
            fmt.Print(op%8,",")
            i+=2
        case 6:
            B = A / int64(math.Pow(2, float64(op)))
            i+=2
        case 7:
            C = A / int64(math.Pow(2, float64(op)))
            i+=2
        }
    }
}

func day17_valid(A int64,ind int64,inst []int64) bool {
    var i int64 = 0
	var B int64 = 0
	var C int64 = 0
	for i<int64(len(inst)) {
        temp:=inst[i+1];
        var op int64 = 0
        if temp<=3 {
			op=temp;
		} else if temp==4 {
			op=A;
		} else if temp==5 {
			op=B;
		} else if temp==6 {
			op=C;
		}
        switch (inst[i]) {
        case 0:
            A = A / int64(math.Pow(2, float64(op)))
            i+=2
        case 1:
            B=B^temp
            i+=2
        case 2:
            B=op%8
            i+=2
        case 3:
            if A!=0 {
                i=temp
            } else {
				i+=2
			}
        case 4:
            B=B^C
            i+=2
        case 5:
			if (op%8)!=inst[ind] {
				return false
			} else {
				ind++;
			}
            i+=2
        case 6:
            B = A / int64(math.Pow(2, float64(op)))
            i+=2
        case 7:
            C = A / int64(math.Pow(2, float64(op)))
            i+=2
        }
    }
	return true
}

func day17_helper(A int64,i int64,inst []int64) bool {
    if i==-1 {
        fmt.Println(A)
		return true
	}
    for j:=0; j<8; j++ {
        temp:=int64(A*8)+int64(j)
        if day17_valid(temp,i,inst) {
            if day17_helper(temp,i-1,inst) {
                return true
            }
        }
    }
    return false
}

func day17_part2(lines []string) {
	program := strings.Split(lines[4][strings.Index(lines[4],": ")+2:],",")
    inst := make([]int64,0)
    for _,v := range program {
		val, _ := strconv.ParseInt(strings.TrimSpace(v),10,64)
		inst = append(inst, val)
	}
	day17_helper(0,int64(len(inst)-1),inst)
}

func Day17() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Split(string(data), "\n")
	fmt.Println("Part 1:")
	day17_part1(lines)
	fmt.Println("\nPart 2:")
	day17_part2(lines)
}