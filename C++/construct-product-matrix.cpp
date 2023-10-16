// Time:  O(m * n)
// Space: O(m * n)

// prefix sum
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        static const int MOD = 12345;

        vector<int64_t> right(size(grid) * size(grid[0]) + 1, 1);
        for (int i = size(grid) - 1; i >= 0; --i) {
            for (int j = size(grid[0]) - 1; j >= 0; --j) {
                right[i * size(grid[0]) + j] = (right[(i * size(grid[0]) + j) + 1] * grid[i][j]) % MOD;
            }
        }
        int64_t left = 1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                const int x = grid[i][j];
                grid[i][j] = (left * right[(i * size(grid[0]) + j) + 1]) % MOD;
                left = (left * x) % MOD;
            }
        }
        return grid;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// prefix sum
class Solution2 {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        static const int MOD = 12345;

        vector<int64_t> left(size(grid) * size(grid[0]) + 1, 1);        
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                left[(i * size(grid[0]) + j) + 1] = (left[i * size(grid[0]) + j] * grid[i][j]) % MOD;
            }
        }
        vector<int64_t> right(size(grid) * size(grid[0]) + 1, 1);
        for (int i = size(grid) - 1; i >= 0; --i) {
            for (int j = size(grid[0]) - 1; j >= 0; --j) {
                right[i * size(grid[0]) + j] = (right[(i * size(grid[0]) + j) + 1] * grid[i][j]) % MOD;
            }
        }
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                grid[i][j] = (left[i * size(grid[0]) + j] * right[(i * size(grid[0]) + j) + 1]) % MOD;
            }
        }
        return grid;
    }
};
