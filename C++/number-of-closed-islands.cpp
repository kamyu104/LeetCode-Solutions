// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); ++j) {
            fill(&grid, 0, j);
            fill(&grid, grid.size() - 1, j);
        }
        for (int i = 1; i + 1 < grid.size(); ++i) {
            fill(&grid, i, 0);
            fill(&grid, i, grid[0].size() - 1);
        }
        int result = 0;
        for (int i = 1; i + 1 < grid.size(); ++i) {
            for (int j = 1; j + 1 < grid[0].size(); ++j) {
                if (fill(&grid, i, j)) {
                    ++result;
                }
            }
        }
        return result;
    }

private:
    bool fill(vector<vector<int>> *grid, int i, int j) {
        static vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        if (i < 0 || j < 0 ||
            i >= grid->size() || j >= (*grid)[i].size() ||
            (*grid)[i][j]) {
            return false;
        }
        (*grid)[i][j] = 1;
        for (const auto& [dx, dy] : directions) {
            fill(grid, i + dx, j + dy);
        }
        return true;
    }
};
