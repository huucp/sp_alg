package main

import "fmt"

func maxProduct(nums []int) int {
	maxIndex := 0
	maxIndex2nd := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[maxIndex] {
			maxIndex2nd = maxIndex
			maxIndex = i
		} else if nums[i] > nums[maxIndex2nd] {
			maxIndex2nd = i
		}
	}

	return (nums[maxIndex] - 1) * (nums[maxIndex2nd] - 1)

}

func main() {
	nums := []int{1, 5, 4, 5}
	fmt.Println(maxProduct(nums))
}
