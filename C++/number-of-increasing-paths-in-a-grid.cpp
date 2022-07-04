// Time:  O(m * n)
// Space: O(m * n)

// topological sort, bottom-up dp
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        static const int MOD = 1e9 + 7;
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> in_degree(size(grid), vector<int>(size(grid[0])));
        vector<pair<int, int>> q;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                for (const auto& [di, dj] : directions) {
                    const int ni = i + di, nj = j + dj;
                    if (0 <= ni && ni < size(grid) &&
                        0 <= nj && nj < size(grid[0]) &&
                        grid[i][j] > grid[ni][nj]) {
                        ++in_degree[i][j];
                    }
                }
                if (!in_degree[i][j]) {
                    q.emplace_back(i, j);
                }
            }
        }
        vector<vector<int>> dp(size(grid), vector<int>(size(grid[0]), 1));
        int result = 0;
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [i, j] : q) {
                result = (result + dp[i][j]) % MOD;
                for (const auto& [di, dj] : directions) {
                    const int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < size(grid) &&
                          0 <= nj && nj < size(grid[0]) &&
                          grid[i][j] < grid[ni][nj])) {
                        continue;
                    }
                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                    --in_degree[ni][nj];
                    if (!in_degree[ni][nj]) {
                        new_q.emplace_back(ni, nj);
                    }
                }
            }
            q = move(new_q);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// top-down dp, memoization
class Solution2 {
public:
    int countPaths(vector<vector<int>>& grid) {
        static const int MOD = 1e9 + 7;
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> lookup(size(grid), vector<int>(size(grid[0])));
        const function<int(int, int)> memoization = [&](int i, int j) {
            if (!lookup[i][j]) {
                lookup[i][j] = 1;
                for (const auto& [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (0 <= ni && ni < size(grid) &&
                        0 <= nj && nj < size(grid[0]) &&
                        grid[i][j] < grid[ni][nj]) {
                        lookup[i][j] = (lookup[i][j] + memoization(ni, nj)) % MOD;
                    }
                }
            }
            return lookup[i][j];
        };
        int result = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                result = (result + memoization(i, j)) % MOD;
            }
        }
        return result;
    }
};
