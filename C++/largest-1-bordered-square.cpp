// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        auto left(grid), top(grid);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                if (i) {
                    top[i][j] = top[i - 1][j] + 1;
                }
                if (j) {
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
        }
        for (int l = min(grid.size(), grid[0].size()); l >= 1; --l) {
            for (int i = 0; i <= grid.size() - l; ++i) {
                for (int j = 0; j <= grid[0].size() - l; ++j) {
                    if (min({top[i + l - 1][j],
                             top[i + l - 1][j + l - 1],
                             left[i][j + l - 1],
                             left[i + l - 1][j + l - 1]}) >= l) {
                        return l * l;
                    }
                }
            }
        }
        return 0;
    }
};
