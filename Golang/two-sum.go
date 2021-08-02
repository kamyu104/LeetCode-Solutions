// Time:  O(n)
// Space: O(n)

func twoSum(nums []int, target int) []int {
	lookup := make(map[int]int)
	for i, x := range nums {
		if j, ok := lookup[target-x]; ok {
			return []int{j, i}
		}
		lookup[x] = i
	}
	return nil
}
