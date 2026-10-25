// Time:  O(m * n)
// Space: O(1)

// simulation
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        static const unordered_map<char, pair<int, int>>& LOOKUP = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};

        int r = 0, c = 0;
        for (;;) {
            const auto& [dr, dc] = LOOKUP.at(grid[r][c]);
            grid[r][c] = '#';
            const auto& [nr, nc] = pair(r + dr, c + dc);
            if (!(0 <= nr && nr < size(grid) && 0 <= nc && nc < size(grid[0]) && grid[nr][nc] != '#')) {
                break;
            }
            tie(r, c) = pair(nr, nc);
        }
        return {r, c};
    }
};
