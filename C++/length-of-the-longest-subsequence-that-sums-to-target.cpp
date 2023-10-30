// Time:  O(n * t)
// Space: O(t)

// knapsack dp
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;
        for (const auto& x : nums) {
            for (int i = size(dp) - 1; i - x >= 0; --i) {
                if (dp[i - x] != -1) {
                    dp[i] = max(dp[i], dp[i - x] + 1);
                }
            }
        }
        return dp[target];
    }
};
