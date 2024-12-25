// Time:  O(m * n * r)
// Space: O(n * r)

// dp
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        static const int MOD = 1e9 + 7;
        static const int MAX_R = 16;
        vector<vector<int>> dp(size(grid[0]), vector<int>(MAX_R));
        dp[0][0] = 1;
        for (int i = 0; i < size(grid); ++i) {
            vector<vector<int>> new_dp(size(grid[0]), vector<int>(MAX_R));
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int v = 0; v < MAX_R; ++v) {
                    new_dp[j][v ^ grid[i][j]] = (dp[j][v] + (j - 1 >= 0 ? new_dp[j - 1][v] : 0)) % MOD;
                }
            }
            dp = move(new_dp);
        }
        return dp.back()[k];
    }
};
