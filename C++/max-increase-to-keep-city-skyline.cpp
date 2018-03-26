// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row_maxes(grid.size());
        vector<int> col_maxes(grid[0].size());
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                row_maxes[r] = max(row_maxes[r], grid[r][c]);
                col_maxes[c] = max(col_maxes[c], grid[r][c]);
            }
        }
        int result = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                result += min(row_maxes[r], col_maxes[c]) - grid[r][c];
            }
        }
        return result;
    }
};
