// Time:  O(m * n)
// Space: O(min(m, n))

// dp
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        static const int MOD = 1e9 + 7;

        const auto& get = [&](int r, int c) {
            return size(grid) > size(grid[0]) ? grid[r][c] : grid[c][r];
        };

        vector<pair<int, int>> dp(min(size(grid), size(grid[0])) + 1);
        dp[1] = pair(1, 1);
        for (int r = 0; r < max(size(grid), size(grid[0])); ++r) {
            for (int c = 0; c + 1 < size(dp); ++c) {
                if (get(r, c)) {
                    dp[c + 1] = pair(dp[c + 1].second, dp[c].first);
                } else {
                    dp[c + 1] = pair((dp[c + 1].second + dp[c].first) % MOD,
                                     (dp[c + 1].second + dp[c].first) % MOD);
                }
            }
        }
        return dp.back().first;
    }
};

// Time:  O(m * n)
// Space: O(n)
// dp
class Solution2 {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        static const int MOD = 1e9 + 7;

        vector<pair<int, int>> dp(size(grid[0]) + 1);
        dp[1] = pair(1, 1);
        for (int r = 0; r < size(grid); ++r) {
            for (int c = 0; c < size(grid[0]); ++c) {
                if (grid[r][c]) {
                    dp[c + 1] = pair(dp[c + 1].second, dp[c].first);
                } else {
                    dp[c + 1] = pair((dp[c + 1].second + dp[c].first) % MOD,
                                     (dp[c + 1].second + dp[c].first) % MOD);
                }
            }
        }
        return dp.back().first;
    }
};
