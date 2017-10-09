// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int length = 0;
                if (dfs(i, j, &grid, &length)) {
                    result = max(result, length);
                }
            }
        }
        return result;
    }

private:
    bool dfs(const int i, const int j, vector<vector<int>> *grid, int *length) {
        static const vector<pair<int, int>> directions{{-1,  0}, { 1,  0},
                                                       { 0,  1}, { 0, -1}};
        if (i < 0 || i >= grid->size() ||
            j < 0 || j >= (*grid)[0].size() ||
            (*grid)[i][j] <= 0) {
            return false;
        }
        (*grid)[i][j] *= -1;
        ++(*length);
        for (const auto& d : directions) {
            dfs(i + d.first, j + d.second, grid, length);
        }
        return true;
    }
};
