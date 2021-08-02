// Time:  O(n)
// Space: O(n)

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> lookup = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (lookup.containsKey(target - nums[i])) {
                return new int[] { lookup.get(target - nums[i]), i };
            }
            lookup.put(nums[i], i);
        }
        return null;
    }
}
