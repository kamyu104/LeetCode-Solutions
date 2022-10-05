// Time:  O(m * n)
// Space: O(1)

// brute force
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        const auto& total = [&](int i, int j) {
            return grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + 
                                grid[i + 1][j + 1] + 
                   grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        };

        int result = 0;
        for (int i = 0; i + 2 < size(grid); ++i) {
            for (int j = 0; j + 2 < size(grid[0]); ++j) {
                result = max(result, total(i, j));
            }
        }
        return result;
    }
};
