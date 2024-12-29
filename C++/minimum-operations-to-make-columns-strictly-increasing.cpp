// Time:  O(m * n)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int result = 0;
        for (int j = 0; j < size(grid[0]); ++j) {
            for (int i = 0; i + 1 < size(grid); ++i) {
                if (grid[i][j] + 1 <= grid[i + 1][j]) {
                    continue;
                }
                result += (grid[i][j] + 1) - grid[i + 1][j];
                grid[i + 1][j] = grid[i][j] + 1;
            }
        }
        return result;
    }
};
