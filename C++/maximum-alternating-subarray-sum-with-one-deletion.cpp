// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        int64_t result = NEG_INF;
        vector<vector<int64_t>> dp(2, vector<int64_t>(2, NEG_INF));
        for (const auto& x : nums) {
            dp[1] = {
                max(dp[1][1] != NEG_INF ? dp[1][1] + x : NEG_INF, dp[0][0]),
                max(dp[1][0] != NEG_INF ? dp[1][0] - x : NEG_INF, dp[0][1])
            };
            dp[0] = {
                max<int64_t>(dp[0][1], 0) + x,
                dp[0][0] != NEG_INF ? dp[0][0] - x : NEG_INF
            };
            result = max({result, ranges::max(dp[0]), ranges::max(dp[1])});
        }
        return result;
    }
};
