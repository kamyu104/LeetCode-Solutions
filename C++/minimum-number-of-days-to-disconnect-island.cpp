// Time:  O(m^2 * n^2)
// Space: O(m * n)

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        if (count_islands(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                grid[i][j] = 0;
                int islands_cnt = count_islands(grid);
                grid[i][j] = 1;
                if (islands_cnt != 1) {
                    return 1;
                }
            }
        }
        return 2;
    }

private:
    int count_islands(const vector<vector<int>>& grid) {
        vector<vector<int>> lookup(grid.size(), vector<int>(grid[0].size()));
        int islands_cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 || lookup[i][j]) {
                    continue;
                }
                ++islands_cnt;
                floodfill(grid, i, j, &lookup);
            }
        }
        return islands_cnt;
    }

    void floodfill(const vector<vector<int>>& grid, int i, int j, vector<vector<int>> *lookup) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<pair<int, int>> stk = {{i, j}};
        (*lookup)[i][j] = 1;
        while (!stk.empty()) {
            auto [i, j] = stk.back(); stk.pop_back();
            for (const auto& [di, dj] : directions) {
                const auto& [ni, nj] = pair(i + di, j + dj);
                if (!(0 <= ni && ni < grid.size() &&
                      0 <= nj && nj < grid[0].size() &&
                      grid[ni][nj] &&
                      !(*lookup)[ni][nj])) {
                    continue;
                }
                (*lookup)[ni][nj] = 1;
                stk.emplace_back(ni, nj);
            }
        }
    }
};
