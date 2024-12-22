package main

import (
	"fmt"
	"os"
	"strings"
)

func day9_part1(lines []string) {
	var res int64 = 0
	diskmap := lines[0]
	mp := make([]int64,0)
	id := 0
	for i := 0; i < len(diskmap); i++ {
		ct := diskmap[i]-'0'
		if i%2 == 0 {
			for ct > 0 {
				mp = append(mp, int64(id))
				ct--
			}
			id++
		} else {
			for ct > 0 {
				mp = append(mp, -1)
				ct--
			}
		}
	}
	l := 0
	r := len(mp) - 1
	for mp[l]!=-1 {
		l++
	}
	for mp[r]==-1 {
		r--
	}
	for l < r {
		mp[l], mp[r] = mp[r], mp[l]
		for mp[l]!=-1 {
			l++
		}
		for mp[r]==-1 {
			r--
		}
	}
	for i := 0; i < len(mp); i++ {
		if mp[i] == -1 {
			break
		}
		res += int64(i)*mp[i]
	}
	fmt.Print(res)
}

func day9_part2(lines []string) {
    var res int64 = 0
	diskmap := lines[0]
	mp := make([]int64,0)
	var id int64 = 0
	for i := 0; i < len(diskmap); i++ {
		ct := diskmap[i]-'0'
		if i%2 == 0 {
			for ct > 0 {
				mp = append(mp, int64(id))
				ct--
			}
			id++
		} else {
			for ct > 0 {
				mp = append(mp, -1)
				ct--
			}
		}
	}
	n := len(mp)
	id = mp[n-1]
	for id!=0 {
		r := n-1
		for r>=0 && mp[r]!=id {
			r--
		}
		tempr := r
		blocklen := 0
		for tempr>=0 && mp[tempr] == id {
			blocklen++
			tempr--
		}
		l := 0
		for l<n && mp[l]!=-1 {
			l++
		}
		templ := l
		spacelen := 0
		for templ<n && mp[templ] == -1 {
			spacelen++
			templ++
		}
		for l < n && spacelen < blocklen {
			l = templ
			for l<n && mp[l]!=-1 {
				l++
			}
			templ = l
			spacelen = 0
			for templ<n && mp[templ] == -1 {
				spacelen++
				templ++
			}
		}
		tempr++
		if l+spacelen <= tempr {
			k := 0
			templ = l
			for k < blocklen {
				mp[templ] = mp[tempr]
				mp[tempr] = -1
				templ++
				tempr++
				k++
			}
		}
		id--
	}
	for i := 0; i < len(mp); i++ {
		if mp[i] != -1 {
			res += int64(i)*mp[i]
		}
	}
	fmt.Print(res)
}

func Day9() {
	data, _ := os.ReadFile("input.txt")
	lines := strings.Fields(string(data))
	fmt.Println("Part 1:")
	day9_part1(lines)
	fmt.Println("\nPart 2:")
	day9_part2(lines)
}