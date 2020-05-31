// Time:  O(m * n^2)
// Space: O(n^2)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(2,
            vector<vector<int>>(grid[0].size() + 2,
              vector<int>(grid[0].size() + 2, numeric_limits<int>::min())));
        
        dp[0][1][grid[0].size()] = grid[0][0] + grid[0][grid[0].size() - 1];
        int result = 0;
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j <= grid[0].size(); ++j) {
                for (int k = 1; k <= grid[0].size(); ++k) {
                    int max_prev_dp = numeric_limits<int>::min();
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            max_prev_dp = max(max_prev_dp, dp[(i - 1) % 2][j + d1][k + d2]);
                        }
                    }
                    dp[i % 2][j][k] = (max_prev_dp == numeric_limits<int>::min()) ? numeric_limits<int>::min() :
                                      max_prev_dp + ((j != k) ? (grid[i][j - 1] + grid[i][k - 1]) : grid[i][j - 1]);
                    result = max(result, dp[i % 2][j][k]);
                }
            }
        }
        return result;
    }
};

// Time:  O(m * n^2)
// Space: O(n^2)
class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(2,
            vector<vector<int>>(grid[0].size(),
              vector<int>(grid[0].size(), numeric_limits<int>::min())));
        
        dp[0][0][grid[0].size() - 1] = grid[0][0] + grid[0][grid[0].size() - 1];
        int result = 0;
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                for (int k = 0; k < grid[0].size(); ++k) {
                    int max_prev_dp = numeric_limits<int>::min();
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        if (!(0 <= j + d1 && j + d1 < grid[0].size())) {
                            continue;
                        }
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            if (!(0 <= k + d2 && k + d2 < grid[0].size())) {
                                continue;
                            }
                            max_prev_dp = max(max_prev_dp, dp[(i - 1) % 2][j + d1][k + d2]);
                        }
                    }
                    dp[i % 2][j][k] = (max_prev_dp == numeric_limits<int>::min()) ? numeric_limits<int>::min() :
                                      max_prev_dp + ((j != k) ? (grid[i][j] + grid[i][k]) : grid[i][j]);
                    result = max(result, dp[i % 2][j][k]);
                }
            }
        }
        return result;
    }
};
