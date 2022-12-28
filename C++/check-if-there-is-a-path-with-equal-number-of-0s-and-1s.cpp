// Time:  O(m * n)
// Space: O(n)

// dp
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        if ((size(grid) + size(grid[0]) - 1) % 2) {
            return false;
        }
        vector<vector<int>> dp_left(2, vector<int>(size(grid[0]) + 1, numeric_limits<int>::max()));
        dp_left[0][1] = dp_left[1][0] = 0;
        vector<vector<int>> dp_right(2, vector<int>(size(grid[0]) + 1, numeric_limits<int>::min()));
        dp_right[0][1] = dp_right[1][0] = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                dp_left[(i + 1) % 2][j + 1] = min(dp_left[i % 2][j + 1], dp_left[(i + 1) % 2][j]) + grid[i][j];
                dp_right[(i + 1) % 2][j + 1] = max(dp_right[i % 2][j + 1], dp_right[(i + 1) % 2][j]) + grid[i][j];
            }
        }
        return dp_left[size(grid) % 2].back() <= (size(grid) + size(grid[0]) - 1) / 2 &&
               (size(grid) + size(grid[0]) - 1) / 2 <= dp_right[size(grid) % 2].back();
    }
};
