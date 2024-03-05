// Time:  O(n^2)
// Space: O(1)

// array
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<vector<int>> cnt(2, vector<int>(3));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                ++cnt[(i <= (size(grid[0]) - 1) / 2 && (i - j == 0 || i + j == size(grid[0]) - 1)) || (i > (size(grid[0]) - 1) / 2 && j == (size(grid[0]) - 1) / 2)][grid[i][j]];
            }
        }
        int mx = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j == i) {
                    continue;
                }
                mx = max(mx, cnt[0][i] + cnt[1][j]);
            }
        }
        return size(grid) * size(grid[0]) - mx;
    }
};
