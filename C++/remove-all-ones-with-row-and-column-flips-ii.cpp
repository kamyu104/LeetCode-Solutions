// Time:  O(m * n * 2^(m * n))
// Space: O(2^(m * n))

// dp, bitmasks
class Solution {
public:
    int removeOnes(vector<vector<int>>& grid) {
        static const int INF = numeric_limits<int>::max();

        vector<int> rows(size(grid));
        int mask = 0, bit = 1;
        for (int j = 0; j < size(grid[0]); ++j) {
            mask += bit;
            bit <<= 1;
        }
        for (int i = 0; i < size(grid); ++i) {
            rows[i] = mask;
            mask <<= size(grid[0]);
        }

        vector<int> cols(size(grid[0]));
        mask = 0, bit = 1;
        for (int i = 0; i < size(grid); ++i) {
            mask += bit;
            bit <<= size(grid[0]);
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            cols[j] = mask;
            mask <<= 1;
        }

        int full_mask = (1 << (size(grid) * size(grid[0]))) - 1;
        vector<vector<int>> masks(size(grid), vector<int>(size(grid[0]), full_mask));
        int target = 0;
        bit = 1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                target += bit * grid[i][j];
                masks[i][j] -= (rows[i] + cols[j] - bit);
                bit <<= 1;
            }
        }

        vector<int> dp(target + 1, INF);
        dp[0] = 0;
        for (int mask = 1; mask <= target; ++mask) {
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    if (grid[i][j] && dp[mask & masks[i][j]] != INF) {
                        dp[mask] = min(dp[mask], dp[mask & masks[i][j]] + 1);
                    }
                }
            }
        }
        return dp[target];
    }
};
