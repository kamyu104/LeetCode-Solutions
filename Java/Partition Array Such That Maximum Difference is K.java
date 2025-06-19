class Solution {

    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        int rec = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
            }
        }
        return ans;
    }
}
