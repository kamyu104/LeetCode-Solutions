// Time:  O(m * n * 2^n)
// Space: O(2^n)

// dp with rolling window
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int total = 1 << size(cost[0]);
        vector<vector<int>> dp(2, vector<int>(total, numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 0; i < size(cost); ++i) {
            dp[(i + 1) % 2] = vector<int>(total, numeric_limits<int>::max());
            for (int mask = 0; mask < total; ++mask) {
                for (int j = 0, base = 1; j < size(cost[0]); ++j, base <<= 1) {
                    if (dp[i % 2][mask] > numeric_limits<int>::max() - cost[i][j]) {
                        continue;
                    }
                    dp[i % 2][mask | base] = min(dp[i % 2][mask | base], cost[i][j] + dp[i % 2][mask]);
                    dp[(i + 1) % 2][mask | base] = min(dp[(i + 1) % 2][mask | base], cost[i][j] + dp[i % 2][mask]);
                }
            }
        }
        return dp[size(cost) % 2].back();
    }
};
