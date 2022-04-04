// Time:  O(k * n) = O(n)
// Space: O(k) = O(1)

// dp
class Solution {
public:
    long long numberOfWays(string s) {
        static const int K = 3;
        vector<vector<int64_t>> dp(K, vector<int64_t>(2));  // dp[i][j]: number of ways of selecting i+1 buildings ending with type j
        for (const auto& c : s) {
            int j = c - '0';
            ++dp[0][j];
            for (int i = 1; i < size(dp); ++i) {
                dp[i][j] += dp[i - 1][1 ^ j];
            }
        }
        return dp.back()[0] + dp.back()[1];
    }
};
