package twoSum

func twoSum(nums []int, target int) []int {
	lookup := make(map[int]int)
	for i, num := range nums {
		if j, ok := lookup[target-num]; ok {
			return []int{j, i}
		}
		lookup[nums[i]] = i
	}
	return nil
}
