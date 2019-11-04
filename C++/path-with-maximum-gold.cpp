// Time:  O(m^2 * n^2)
// Space: O(m * n)

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    result = max(result, backtracking(&grid, i, j));
                }
            }
        }
        return result;
    }

private:
    int backtracking(vector<vector<int>> *grid, int i, int j) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};
        int result = 0;
        (*grid)[i][j] *= -1;
        for (const auto& [dx, dy] : directions) {
            int ni = i + dx;
            int nj = j + dy;
            if (!(0 <= ni && ni < grid->size() &&
                  0 <= nj && nj < (*grid)[0].size() &&
                  (*grid)[ni][nj] > 0)) {
                continue;
            }
            result = max(result, backtracking(grid, ni, nj));
        }
        (*grid)[i][j] *= -1;
        return (*grid)[i][j] + result;
    }
};
