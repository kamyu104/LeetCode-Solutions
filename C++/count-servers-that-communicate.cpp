// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size()), columns(grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    ++rows[i], ++columns[j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] && (rows[i] > 1 || columns[j] > 1)) {
                    ++result;
                }
            }
        }
        return result;
    }
};
