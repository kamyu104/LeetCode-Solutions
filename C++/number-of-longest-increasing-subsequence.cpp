// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        auto result = 0, max_len = 0;
        vector<pair<int, int>> dp(nums.size(), {1, 1});  // {length, number} pair
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first == dp[j].first + 1) {
                        dp[i].second += dp[j].second;
                    } else if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                }
            }
            if (max_len == dp[i].first) {
                result += dp[i].second;
            } else if (max_len < dp[i].first) {
                max_len = dp[i].first;
                result = dp[i].second;
            }
        }
        return result;
    }
};
