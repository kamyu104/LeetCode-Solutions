// Time:  O(m * n)
// Space: O(m * n)

// top-down dp, memoization
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        static const int MOD = 1e9 + 7;
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> lookup(size(grid), vector<int>(size(grid[0]), -1));
        const function<int(int, int)> memoization = [&](int i, int j) {
            if (lookup[i][j] == -1) {
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
