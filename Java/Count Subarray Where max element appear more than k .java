class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int maxVal = 0;
        for (int v : nums) maxVal = Math.max(maxVal, v);

        long res = 0;
        int count = 0, left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == maxVal) count++;
            while (count >= k) {
                if (nums[left] == maxVal) count--;
                left++;
            }
            res += left;
        }
        return res;
    }
}
