// Time:  O(k * n)
// Space: O(n)

// prefix sum, dp
class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        static const int NEG_INF = numeric_limits<int>::min();
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> dp(size(nums) + 1, NEG_INF);
        dp[0] = 0;
        for (int i = 1; i <= k; ++i) {
            vector<int> new_dp(size(nums) + 1, NEG_INF);
            int mx = NEG_INF;
            for (int j = i * m - 1; j < size(nums); ++j) {
                mx = max(mx, dp[j - m + 1]);
                new_dp[j + 1] = prefix[j + 1] - prefix[j - m + 1] + mx;
                if (j != i * m - 1) {
                    new_dp[j + 1] = max(new_dp[j + 1], new_dp[j] + nums[j]);
                }
            }
            dp = move(new_dp);
        }
        return ranges::max(dp);
    }     
};
