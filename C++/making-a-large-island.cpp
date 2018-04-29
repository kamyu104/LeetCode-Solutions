// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int result = 0;
        unordered_map<int, int> area;
        int index = 2;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] != 1) {
                    continue;
                }
                area[index] = dfs(r, c, index, &grid);
                result = max(result, area[index++]);
            }
        }

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] != 0) {
                    continue;
                }
                unordered_set<int> seen;
                for (const auto& d :directions) {
                    int nr = r + d.first, nc = c + d.second;
                    if (0 <= nr && nr < grid.size() &&
                        0 <= nc && nc < grid[0].size() &&
                        grid[nr][nc] > 1) {
                        seen.emplace(grid[nr][nc]);
                    }
                }
                int sum = 0;
                for (const auto& i : seen) {
                    sum += area[i];
                }
                result = max(result, 1 + sum);
            }
        }
        return result;
    }

private:
    const vector<pair<int, int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int dfs(int r, int c, int index, vector<vector<int>> *grid) {
        if (!(0 <= r && r < grid->size() &&
              0 <= c && c < (*grid)[0].size() &&
              (*grid)[r][c] == 1)) {
            return 0;
        }
        int result = 1;
        (*grid)[r][c] = index;
        for (const auto& d :directions) {
            result += dfs(r + d.first, c + d.second, index, grid);
        }
        return result;
    }
};
