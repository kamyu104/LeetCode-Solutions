// Time:  O(n * m)
// Space: O(n * m)

// dp
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int n = size(grid);
        const int m = size(grid[0]);
        int result = 0;
        vector<vector<int>> down_right(n, vector<int>(m, 1));
        vector<vector<int>> down_left(n, vector<int>(m, 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int x = grid[i][j];
                if (x == 1) {
                    result = 1;
                    continue;
                }
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 2 - x) {
                    down_right[i][j] = down_right[i - 1][j - 1] + 1;
                }
                if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == 2 - x) {
                    down_left[i][j] = down_left[i - 1][j + 1] + 1;
                }
            }
        }
        vector<vector<int>> up_right(n, vector<int>(m, 1));
        vector<vector<int>> up_left(n, vector<int>(m, 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                const int x = grid[i][j];
                if (x == 1) {
                    continue;
                }
                if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 2 - x) {
                    up_right[i][j] = up_right[i + 1][j - 1] + 1;
                }
                if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == 2 - x) {
                    up_left[i][j] = up_left[i + 1][j + 1] + 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int x = grid[i][j];
                if (x == 1) {
                    continue;
                }
                if ((down_right[i][j] % 2 == 0 && x == 0) || (down_right[i][j] % 2 == 1 && x == 2)) {
                    const int ni = i - down_right[i][j];
                    const int nj = j - down_right[i][j];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == 1) {
                        result = max(result, down_right[i][j] + up_right[i][j]);  // >
                    }
                }
                if ((down_left[i][j] % 2 == 0 && x == 0) || (down_left[i][j] % 2 == 1 && x == 2)) {
                    const int ni = i - down_left[i][j];
                    const int nj = j + down_left[i][j];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == 1) {
                        result = max(result, down_left[i][j] + down_right[i][j]);  // v
                    }
                }
                if ((up_left[i][j] % 2 == 0 && x == 0) || (up_left[i][j] % 2 == 1 && x == 2)) {
                    const int ni = i + up_left[i][j];
                    const int nj = j + up_left[i][j];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == 1) {
                        result = max(result, up_left[i][j] + down_left[i][j]);  // <
                    }
                }
                if ((up_right[i][j] % 2 == 0 && x == 0) || (up_right[i][j] % 2 == 1 && x == 2)) {
                    const int ni = i + up_right[i][j];
                    const int nj = j - up_right[i][j];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] == 1) {
                        result = max(result, up_right[i][j] + up_left[i][j]);  // ^
                    }
                }
            }
        }
        return result;
    }
};

// Time:  O(n * m)
// Space: O(n * m)
// memoization
class Solution2 {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int n = size(grid);
        const int m = size(grid[0]);
        vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        // be careful with the order, going from smaller dimensions to larger dimensions
        vector<vector<vector<vector<vector<int>>>>> lookup(2, vector<vector<vector<vector<int>>>>(3, vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(m)))));
        const function<int (int, int, int, int, int)> memoization = [&](int i, int j, int x, int d, int k) {
            if (!(0 <= i && i < n && 0 <= j && j < m)) {
                return 0;
            }
            if (grid[i][j] != x) {
                return 0;
            }
            if (lookup[k][x][d][i][j] == 0) {
                const int ni = i + directions[d].first;
                const int nj = j + directions[d].second;
                const int nx = x == 2 ? 0 : 2;
                int result = memoization(ni, nj, nx, d, k) + 1;
                if (k != 1) {
                    const int nd = (d + 1) % 4;
                    result = max(result, memoization(ni, nj, nx, nd, k + 1) + 1);
                }
                lookup[k][x][d][i][j] = result;
            }
            return lookup[k][x][d][i][j];
        };
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        result = max(result, memoization(i, j, 1, d, 0));
                    }
                }
            }
        }
        return result;
    }
};
