// Time:  O(m^2 * n)
// Space: O(m * n)

// simulation
class Solution {
public:
    vector<vector<char>> finalGrid(vector<vector<char>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        static const vector<pair<int, int>> NEIGHBORS = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        vector<pair<int, int>> bombs;
        for (int r = 0; r < size(grid); ++r) {
            for (int c = 0; c < size(grid[0]); ++c) {
                if (grid[r][c] == '*') {
                    bombs.emplace_back(r, c);
                }
            }
        }
        for (int _ = 0; _ < size(grid); ++_) {
            bool changed = false;
            vector<pair<int, int>> exploded;
            for (const auto& [r, c] : bombs) {
                for (const auto& [dr, dc] : DIRECTIONS) {
                    const auto& nr = r + dr, &nc = c + dc;
                    if (0 <= nr && nr < size(grid) && 0 <= nc && nc < size(grid[0]) && grid[nr][nc] == '#') {
                        exploded.emplace_back(r, c);
                        break;
                    }
                }
            }
            for (const auto& [r, c] : exploded) {
                for (const auto& [dr, dc] : NEIGHBORS) {
                    const auto& nr = r + dr, &nc = c + dc;
                    if (0 <= nr && nr < size(grid) && 0 <= nc && nc < size(grid[0]) && grid[nr][nc] == '#') {
                        grid[nr][nc] = '-';
                        changed = true;
                    }
                }
            }
            for (int c = 0; c < size(grid[0]); ++c) {
                for (int r = size(grid) - 2; r >= 0; --r) {
                    if (grid[r][c] == '#' && grid[r + 1][c] == '-') {
                        grid[r][c] = '-';
                        grid[r + 1][c] = '#';
                        changed = true;
                    }
                }
            }
            if (!changed) {
                break;
            }
        }
        return grid;
    }
};
