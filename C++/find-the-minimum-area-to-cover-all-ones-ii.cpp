// Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
// Space: O(1)

// brute force
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            int min_r = size(grid);
            int max_r = -1;
            int min_c = size(grid[0]);
            int max_c = -1;
            for (int i = min_i; i <= max_i; ++i) {
                for (int j = min_j; j <= max_j; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int j = i + 1; j < size(grid); ++j) {
                const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(i + 1, size(grid) - 1, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, 0, j);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int i = j + 1; i < size(grid[0]); ++i) {
                const int b = minimumArea(0, size(grid) - 1, j + 1, i);
                const int c = minimumArea(0, size(grid) - 1, i + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, 0, j);
                result = min(result, a + b + c);
            }
        }
        return result;
    }
};

// Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
// Space: O(n * m)
// brute force
class Solution2 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& rotate = [](const auto& grid) {
            vector<vector<int>> result(size(grid[0]), vector<int>(size(grid)));
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    result[j][(size(grid) - 1) - i] = grid[i][j];
                }
            }
            return result;
        };
    
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            int min_r = size(grid);
            int max_r = -1;
            int min_c = size(grid[0]);
            int max_c = -1;
            for (int i = min_i; i <= max_i; ++i) {
                for (int j = min_j; j <= max_j; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int result = numeric_limits<int>::max();
        for (int _ = 0; _ < 4; ++_) {
            for (int i = 0; i < size(grid); ++i) {
                const int a = minimumArea(0, i, 0, size(grid[0]) - 1);
                for (int j = 0; j < size(grid[0]); ++j) {
                    const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                    const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
                for (int j = i + 1; j < size(grid); ++j) {
                    const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                    const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
            }
            grid = rotate(grid);
        }
        return result;
    }
};
