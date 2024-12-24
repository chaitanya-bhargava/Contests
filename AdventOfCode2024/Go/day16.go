package main

import (
	"container/heap"
	"fmt"
	"math"
	"os"
	"strings"
)

var day16_dx = []int{0,1,0,-1}
var day16_dy = []int{1,0,-1,0}

type Item struct {
    value    []int 
    priority []int   
    index    int   
}

type PriorityQueue []*Item

func (pq PriorityQueue) Less(i, j int) bool {
    // We want Pop to give us the lowest, not highest, priority so we use less than here.
    if pq[i].priority[0] == pq[j].priority[0] {
        if pq[i].priority[1] == pq[j].priority[1] {
            return pq[i].priority[2] < pq[j].priority[2]
        }
        return pq[i].priority[1] < pq[j].priority[1]
    }
    return pq[i].priority[0] < pq[j].priority[0]
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
    pq[i].index = i
    pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
    n := len(*pq)
    item := x.(*Item)
    item.index = n
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    old[n-1] = nil  
    item.index = -1 
    *pq = old[0 : n-1]
    return item
}

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func day16_part1(grid []string) {
    var res int64 = 0
    starti:=len(grid)-2
    startj:=1
    pq := make(PriorityQueue,0)
	item := &Item{
        value:    []int{0,starti,startj,0},
        priority: []int{0,starti,startj,0},
    }
    pq.Push(item)
    dist := make([][]int,len(grid))
	for i := range dist {
        dist[i] = make([]int, len(grid[i]))
		for j := range dist[i] {
			dist[i][j] = math.MaxInt
		}
	}
    dist[starti][startj]=0;
    for len(pq)>0 {
		temp := heap.Pop(&pq).(*Item).value
        x:=temp[1]
        y:=temp[2]
        c:=temp[0]
        dir:=temp[3]
        if grid[x][y]=='E' {
			break
		}
        newx:=x+day16_dx[dir]
        newy:=y+day16_dy[dir]
        if grid[newx][newy]!='#' && dist[newx][newy]>(c-1001) {
            item := &Item{
				value:    []int{c+1,newx,newy,dir},
				priority: []int{c+1,newx,newy,dir},
			}
			pq.Push(item)
			if c+1 < dist[newx][newy] {
				dist[newx][newy] = c+1
			}
        }
        newx=x+day16_dx[(dir+1)%4]
        newy=y+day16_dy[(dir+1)%4]
        if grid[newx][newy]!='#' && dist[newx][newy]>(c-1001) {
			item := &Item{
				value:    []int{c+1001,newx,newy,(dir+1)%4},
				priority: []int{c+1001,newx,newy,(dir+1)%4},
			}
            pq.Push(item)
            if c+1001 < dist[newx][newy] {
				dist[newx][newy] = c+1001
			}
        }
        newx=x+day16_dx[((dir-1)%4+4)%4];
        newy=y+day16_dy[((dir-1)%4+4)%4];
        if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
			item := &Item{
				value:    []int{c+1001,newx,newy,((dir-1)%4+4)%4},
				priority: []int{c+1001,newx,newy,((dir-1)%4+4)%4},
			}
            pq.Push(item)
            if c+1001 < dist[newx][newy] {
				dist[newx][newy] = c+1001
			}
        }
    }
	res = int64(dist[1][len(grid[0])-2])
    fmt.Print(res)
}

func day16_helper(x int,y int,dir int,cost int,path [][]int,sf map[string]bool,dist [][]int){
    if x==1 && y==len(dist[0])-2 {
        if dist[x][y]==cost {
            for _,v:= range path {
                key := fmt.Sprintf("%d,%d", v[0], v[1])
                sf[key]=true
            }
        } else{
            return
        }
    }
    newx:=x+day16_dx[dir]
    newy:=y+day16_dy[dir]
    flag:=false
    if dist[newx][newy]==dist[x][y]+1 {
        path = append(path, []int{newx,newy})
        flag=true
        day16_helper(newx,newy,dir,cost,path,sf,dist);
        path = path[:len(path)-1]
    }
    newx2:=newx+day16_dx[dir]
    newy2:=newy+day16_dy[dir]
    if !flag && dist[newx][newy]!=math.MaxInt && dist[newx2][newy2]==dist[x][y]+2 {
        path = append(path, []int{newx,newy})
        path = append(path, []int{newx2,newy2})
        day16_helper(newx2,newy2,dir,cost,path,sf,dist);
        path = path[:len(path)-1]
        path = path[:len(path)-1]
    }
    newx=x+day16_dx[(dir+1)%4]
    newy=y+day16_dy[(dir+1)%4]
    if dist[newx][newy]!=math.MaxInt && dist[newx][newy]==dist[x][y]+1001 {
        path = append(path, []int{newx,newy})
        day16_helper(newx,newy,(dir+1)%4,cost,path,sf,dist);
        path = path[:len(path)-1]
    }
    newx=x+day16_dx[((dir-1)%4+4)%4]
    newy=y+day16_dy[((dir-1)%4+4)%4]
    if dist[newx][newy]!=math.MaxInt && dist[newx][newy]==dist[x][y]+1001 {
        path = append(path, []int{newx,newy})
        day16_helper(newx,newy,((dir-1)%4+4)%4,cost,path,sf,dist);
        path = path[:len(path)-1]
    }
}

func day16_part2(grid []string) {
	var res int64 = 0
    starti:=len(grid)-2
    startj:=1
    pq := make(PriorityQueue,0)
	item := &Item{
        value:    []int{0,starti,startj,0},
        priority: []int{0,starti,startj,0},
    }
    pq.Push(item)
    dist := make([][]int,len(grid))
	for i := range dist {
        dist[i] = make([]int, len(grid[i]))
		for j := range dist[i] {
			dist[i][j] = math.MaxInt
		}
	}
    dist[starti][startj]=0;
    for len(pq)>0 {
		temp := heap.Pop(&pq).(*Item).value
        x:=temp[1]
        y:=temp[2]
        c:=temp[0]
        dir:=temp[3]
        if grid[x][y]=='E' {
			break
		}
        newx:=x+day16_dx[dir]
        newy:=y+day16_dy[dir]
        if grid[newx][newy]!='#' && dist[newx][newy]>(c-1001) {
            item := &Item{
				value:    []int{c+1,newx,newy,dir},
				priority: []int{c+1,newx,newy,dir},
			}
			pq.Push(item)
			if c+1 < dist[newx][newy] {
				dist[newx][newy] = c+1
			}
        }
        newx=x+day16_dx[(dir+1)%4]
        newy=y+day16_dy[(dir+1)%4]
        if grid[newx][newy]!='#' && dist[newx][newy]>(c-1001) {
			item := &Item{
				value:    []int{c+1001,newx,newy,(dir+1)%4},
				priority: []int{c+1001,newx,newy,(dir+1)%4},
			}
            pq.Push(item)
            if c+1001 < dist[newx][newy] {
				dist[newx][newy] = c+1001
			}
        }
        newx=x+day16_dx[((dir-1)%4+4)%4];
        newy=y+day16_dy[((dir-1)%4+4)%4];
        if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
			item := &Item{
				value:    []int{c+1001,newx,newy,((dir-1)%4+4)%4},
				priority: []int{c+1001,newx,newy,((dir-1)%4+4)%4},
			}
            pq.Push(item)
            if c+1001 < dist[newx][newy] {
				dist[newx][newy] = c+1001
			}
        }
    }
	final:=dist[1][len(grid[0])-2];
	path := make([][]int,0)
    sf := make(map[string]bool)
    path = append(path, []int{len(grid)-2,1})
    day16_helper(len(grid)-2,1,0,final,path,sf,dist)
    res = int64(len(sf))
    fmt.Print(res)
}

func Day16() {
    data, _ := os.ReadFile("input.txt")
    lines := strings.Fields(string(data))
    fmt.Println("Part 1:")
    day16_part1(lines)
    fmt.Println("\nPart 2:")
    day16_part2(lines)
}