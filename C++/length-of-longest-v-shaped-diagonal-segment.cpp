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
