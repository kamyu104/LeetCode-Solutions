// Time:  O(n * m)
// Space: O(1)

// array
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_r = size(grid);
        int max_r = -1;
        int min_c = size(grid[0]);
        int max_c = -1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                min_r = min(min_r, i);
                max_r = max(max_r, i);
                min_c = min(min_c, j);
                max_c = max(max_c, j);
            }
        }
        return (max_r - min_r + 1) * (max_c - min_c + 1);
    }
};
