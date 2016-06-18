// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        vector<vector<int>> right{grid.size(), vector<int>(grid[0].size())};
        vector<vector<int>> down{grid.size(), vector<int>(grid[0].size())};
        for (int i = grid.size() - 1; i >= 0; --i) {
            for (int j = grid[0].size() - 1; j >= 0; --j) {
                if (grid[i][j] != 'Y') {
                    if (i + 1 < grid.size()) {
                        right[i][j] = right[i + 1][j];
                    }
                    if (j + 1 < grid[0].size()) {
                        down[i][j] = down[i][j + 1];
                    }
                    if (grid[i][j] == 'X') {
                        ++right[i][j];
                        ++down[i][j];
                    }
                }
            }
        }
        vector<int> up(grid[0].size());
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int left = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 'Y') {
                    up[j] = 0;
                    left = 0;
                } else if (grid[i][j] == 'X') {
                    ++left;
                    ++up[j];
                } else {
                    result = max(result, left + up[j] + right[i][j] + down[i][j]);
                }
            }
        }
        return result;
    }
};
