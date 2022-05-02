// Time:  O(m * n)
// Space: O(m * n)

// array, simulation
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        enum State {GREEN, RED, BLOCK};
        vector<vector<int>> grid(m, vector<int>(n, GREEN));
        for (const auto& x : guards) {
            grid[x[0]][x[1]] = BLOCK;
        }
        for (const auto& x : walls) {
            grid[x[0]][x[1]] = BLOCK;
        }
        for (const auto& x : guards) {
            for (const auto& [dr, dc] : directions) {
                for (int nr = x[0] + dr, nc = x[1] + dc;
                     0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] != BLOCK;
                     nr += dr, nc += dc) {
                    grid[nr][nc] = RED;
                }
            }
        }
        int result = 0;
        for (const auto& row : grid) {
            for (const auto& x : row) {
                result += (x == GREEN);
            }
        }
        return result;
    }
};
