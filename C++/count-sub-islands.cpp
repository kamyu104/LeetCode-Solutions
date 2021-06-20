// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int result = 0;
        for (int i = 0; i < size(grid2); ++i) {
            for (int j = 0; j < size(grid2[0]); ++j) {
                if (grid2[i][j]) {
                    result += dfs(grid1, &grid2, i, j);
                }
            }
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>>& grid1,
            vector<vector<int>> *grid2,
            int i, int j) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};
        if (!(0 <= i && i < size(*grid2) &&
              0 <= j && j < size((*grid2)[0]) &&
              (*grid2)[i][j] == 1)) {
            return 1;
        }
        (*grid2)[i][j] = 0;
        int result = grid1[i][j];
        for (const auto& [di, dj] : directions) {
            result &= dfs(grid1, grid2, i + di, j + dj);
        }
        return result;
    }
};
