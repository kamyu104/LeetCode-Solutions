// Time:  O(k * m * n + r)
// Space: O(m * n + r)

// dp, prefix sum
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        static const int INF = numeric_limits<int>::max();

        const int m = size(grid), n = size(grid[0]);
        int mx = 0;
        for (const auto& row: grid) {
            const auto& v = ranges::max(row);
            if (v > mx) {
                mx = v;
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, INF));
        dp[m - 1][n - 1]= 0;
        vector<int> prefix(mx + 1, INF);
        for (int i = 0; i <= k; ++i) {
            for (int r = m - 1; r >= 0; --r) {
                for (int c = n - 1; c >= 0; --c) {
                    if (r + 1 < m) {
                        if (dp[r + 1][c] + grid[r + 1][c] < dp[r][c]) {
                            dp[r][c] = dp[r + 1][c] + grid[r + 1][c];
                        }
                    }
                    if (c + 1 < n) {
                        if (dp[r][c + 1] + grid[r][c + 1] < dp[r][c]) {
                            dp[r][c] = dp[r][c + 1] + grid[r][c + 1];
                        }
                    }
                    if (prefix[grid[r][c]] < dp[r][c]) {
                        dp[r][c] = prefix[grid[r][c]];
                    }
                }
            }
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] < prefix[grid[r][c]]) {
                        prefix[grid[r][c]] = dp[r][c];
                    }
                }
            }
            for (int i = 0; i + 1 <= mx; ++i) {
                if (prefix[i] < prefix[i + 1]) {
                    prefix[i + 1] = prefix[i];
                }
            }
        }
        return dp[0][0];
    }
};

// Time:  O(k * m * n + r)
// Space: O(m * n + r)
// dp, prefix sum
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        static const int INF = numeric_limits<int>::max();

        int mx = 0;
        for (const auto& row: grid) {
            mx = max(mx, ranges::max(row));
        }
        vector<vector<int>> dp(size(grid), vector<int>(size(grid[0]), INF));
        dp[size(grid) - 1][size(grid[0]) - 1]= 0;
        vector<int> prefix(mx + 1, INF);
        for (int i = 0; i <= k; ++i) {
            for (int r = size(grid) - 1; r >= 0; --r) {
                for (int c = size(grid[0]) - 1; c >= 0; --c) {
                    if (r + 1 < size(grid)) {
                        dp[r][c] = min(dp[r][c], dp[r + 1][c] + grid[r + 1][c]);
                    }
                    if (c + 1 < size(grid[0])) {
                        dp[r][c] = min(dp[r][c], dp[r][c + 1] + grid[r][c + 1]);
                    }
                    dp[r][c] = min(dp[r][c], prefix[grid[r][c]]);
                }
            }
            for (int r = 0; r < size(grid); ++r) {
                for (int c = 0; c < size(grid[0]); ++c) {
                    prefix[grid[r][c]] = min(prefix[grid[r][c]], dp[r][c]);
                }
            }
            for (int i = 0; i + 1 < size(prefix); ++i) {
                prefix[i + 1] = min(prefix[i + 1], prefix[i]);
            }
        }
        return dp[0][0];
    }
};
