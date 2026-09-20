// Time:  O(n^2)
// Space: O(1)

// array, inplace
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        const auto& rotate = [&](int i, int j) {
            for (int x = grid[i][j]; x > 0; ) {
                const auto& nj = (j - rowShift[i] + size(grid[0])) % size(grid[0]);
                const auto& ni = (i - colShift[nj] + size(grid)) % size(grid);
                const auto nx = grid[ni][nj];
                grid[ni][nj] = -x;
                tie(i, j, x) = tuple(ni, nj, nx);
            }
        };

        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                rotate(i, j);
            }
        }
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                grid[i][j] = -grid[i][j];
            }
        }
        return grid;
    }
};
