package main

import (
	"fmt"
	"sort"
)

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	const MOD int64 = 1e9 + 7
	sort.Ints(horizontalCuts)
	horizontalCuts = append(horizontalCuts, h)
	maxH := horizontalCuts[0]
	for i := 1; i < len(horizontalCuts); i++ {
		if horizontalCuts[i]-horizontalCuts[i-1] > maxH {
			maxH = horizontalCuts[i] - horizontalCuts[i-1]
		}
	}

	sort.Ints(verticalCuts)
	verticalCuts = append(verticalCuts, w)
	maxW := verticalCuts[0]
	for i := 1; i < len(verticalCuts); i++ {
		if verticalCuts[i]-verticalCuts[i-1] > maxW {
			maxW = verticalCuts[i] - verticalCuts[i-1]
		}
	}

	resultInt64 := (int64(maxH) * int64(maxW)) % MOD
	return int(resultInt64)
}

func main() {
	fmt.Println("hello world")

}
