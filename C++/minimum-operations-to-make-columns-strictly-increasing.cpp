// Time:  O(m * n)
// Space: O(1)

// greedy
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i + 1 < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                const int diff = max((grid[i][j] + 1) - grid[i + 1][j], 0);
                grid[i + 1][j] += diff;
                result += diff;
            }
        }
        return result;
    }
};
