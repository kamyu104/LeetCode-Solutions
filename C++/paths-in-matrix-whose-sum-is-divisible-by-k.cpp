// Time:  O(m * n * k)
// Space: O(n * k)

// dp
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> dp(size(grid[0]), vector<int>(k));
        dp[0][0] = 1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                vector<int> cnt(k);
                for (int l = 0; l < k; ++l) {
                    cnt[(l + grid[i][j]) % k] = ((j - 1 >= 0 ? dp[j - 1][l] : 0) + dp[j][l]) % MOD;
                }
                dp[j] = move(cnt);
            }
        }
        return dp.back()[0];
    }
};
