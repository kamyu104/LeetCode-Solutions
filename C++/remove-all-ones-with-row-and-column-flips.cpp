// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        for (int i = 1; i < size(grid); ++i) {
            if (grid[i] == grid[0]) {
                continue;
            }
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j] == grid[0][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
