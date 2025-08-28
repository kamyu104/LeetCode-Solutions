class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        boolean[] seen = new boolean[10001];
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;
        
        for (int right = 0; right < n; right++) {
            while (seen[nums[right]]) {
                currentSum -= nums[left];
                seen[nums[left]] = false;
                left++;
            }
            currentSum += nums[right];
            seen[nums[right]] = true;
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        
        return maxSum;
    }
}
