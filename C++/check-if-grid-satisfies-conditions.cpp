// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int j = 0; j < size(grid[0]); ++j) {
            for (int i = 0; i + 1 < size(grid); ++i) {
                if (grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
            }
            if (j + 1 < size(grid[0]) && grid[0][j] == grid[0][j + 1]) {
                return false;
            }
        }
        return true;
    }
};
