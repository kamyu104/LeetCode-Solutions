// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int area = 0;
                if (dfs(i, j, &grid, &area)) {
                    result = max(result, area);
                }
            }
        }
        return result;
    }

private:
    bool dfs(const int i, const int j, vector<vector<int>> *grid, int *area) {
        static const vector<pair<int, int>> directions{{-1,  0}, { 1,  0},
                                                       { 0,  1}, { 0, -1}};
        if (i < 0 || i >= grid->size() ||
            j < 0 || j >= (*grid)[0].size() ||
            (*grid)[i][j] <= 0) {
            return false;
        }
        (*grid)[i][j] *= -1;
        ++(*area);
        for (const auto& d : directions) {
            dfs(i + d.first, j + d.second, grid, area);
        }
        return true;
    }
};
