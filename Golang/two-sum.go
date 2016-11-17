package leetcode

import "sort"

// Given an array of integers, return indices of the two numbers
// such that they add up to a specific target.
// You may assume that each input would have exactly one solution.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
func TwoSum(nums []int, target int) []int {

	indexs := make([]int, 2)
	hash := map[int]int{}

	for i := range nums {
		hash[target-nums[i]] = i
	}

	for i := range nums {
		index, ok := hash[nums[i]]
		if ok {
			if i == index {
				continue
			}
			indexs[0] = index
			indexs[1] = i
			sort.Ints(indexs)
			break
		}
		continue
	}

	return indexs
}
