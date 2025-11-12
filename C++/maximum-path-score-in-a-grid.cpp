// Time:  O(m * n * k)
// Space: O(m * n * k)

// dp
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}};

        vector<vector<vector<int>>> dp(size(grid), vector<vector<int>>(size(grid[0]), vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int c = 0; c <= k; ++c) {
                    if (dp[i][j][c] == -1) {
                        continue;
                    }
                    for (const auto& [di, dj] : DIRECTIONS) {
                        const int ni = i + di;
                        const int nj = j + dj;
                        if (!(0 <= ni && ni < size(grid) &&
                              0 <= nj && nj < size(grid[0]) &&
                              c + (grid[ni][nj] ? 1 : 0) <= k)) {
                            continue;
                        }
                        const int nc = c + (grid[ni][nj] ? 1 : 0);
                        dp[ni][nj][nc] = max(dp[ni][nj][nc] , dp[i][j][c] + grid[ni][nj]);
                    }
                }
            }
        }
        return ranges::max(dp.back().back());
    }
};
