// Time:  O(m * n^2)
// Space: O(n)

// dp
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(2, vector<int>(size(grid[0])));
        for (int j = 0; j < size(grid[0]); ++j) {
            dp[0][j] = grid[0][j];
        }
        for (int i = 0; i < size(grid) - 1; ++i) {
            dp[(i + 1) % 2] = vector<int>(size(grid[0]), numeric_limits<int>::max());
            for (int k = 0; k < size(grid[0]); ++k) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    dp[(i + 1) % 2][j] = min(dp[(i + 1) % 2][j], dp[i % 2][k] + moveCost[grid[i][k]][j] + grid[i + 1][j]);
                }
            }
        }
        return *min_element(cbegin(dp[(size(grid) - 1) % 2]), cend(dp[(size(grid) - 1) % 2]));
    }
};
