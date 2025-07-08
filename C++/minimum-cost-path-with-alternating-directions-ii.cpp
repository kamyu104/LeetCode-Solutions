// Time:  O(m * n)
// Space: O(n)

// dp
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        waitCost[0][0] = waitCost[m - 1][n - 1] = 0;
        vector<int64_t> dp(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int64_t prev = (i == 0 && j == 0) ? 0 : numeric_limits<int64_t>::max();
                if (i - 1 >= 0) {
                    prev = min(prev, dp[j]);
                }
                if (j - 1 >= 0) {
                    prev = min(prev, dp[j - 1]);
                }
                dp[j] = prev + waitCost[i][j] + static_cast<int64_t>(i + 1) * (j + 1);
            }
        }
        return dp[n - 1];
    }
};
