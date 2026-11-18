// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int64_t dp1 = nums.back(), dp2 = 0;
        for (int i = size(nums) - 2; i >= 0; --i) {
            tie(dp1, dp2) = pair(max(nums[i] + (nums[i] % 3 ? dp1 : -dp1), (nums[i] + nums[i + 1]) + ((nums[i] + nums[i + 1]) % 3 ? dp2 : -dp2)), dp1);
        }
        return dp1;
    }
};
