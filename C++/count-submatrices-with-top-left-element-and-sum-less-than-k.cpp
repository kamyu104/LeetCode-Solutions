// Time:  O(n * m)
// Space: O(1)

// prefix sum
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int result = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if (j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] -= grid[i - 1][j - 1];
                }
                if (grid[i][j] <= k) {
                    ++result;
                }
            }
        }
        return result;
    }
};
