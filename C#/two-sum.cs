// Time:  O(n)
// Space: O(n)

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> lookup = new Dictionary<int, int>();
        for (var i = 0; i < nums.Length; i++) {
            if (lookup.ContainsKey(target - nums[i])) {
                return new int [] { lookup[target - nums[i]], i };
            }
            lookup[nums[i]] = i;
        }
        return new int[] { };
    }
}
