// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int max_row = 0;
            int max_col = 0;
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] > 0) {
                    ++result;
                }
                max_row = max(max_row, grid[i][j]);
                max_col = max(max_col, grid[j][i]);
            }
            result += max_row + max_col;
        }
        return result;
    }
};
