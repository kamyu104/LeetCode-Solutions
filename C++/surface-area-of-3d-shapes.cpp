// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j]) {
                    result += grid[i][j] * 4 + 2;
                }
                if (i) {
                    result -= min(grid[i][j], grid[i - 1][j]) * 2;
                }
                if (j) {
                    result -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return result;
    }
};
