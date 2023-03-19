// Time:  O(m * n)
// Space: O(m * n)

// hash table, simulation
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return false;
        }
        vector<pair<int, int>> lookup(size(grid) * size(grid[0]));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup[grid[i][j]] = {i, j};
            }
        }
        for (int i = 0; i + 1 < size(lookup); ++i) {
            const int dx = abs(lookup[i + 1].first - lookup[i].first);
            const int dy = abs(lookup[i + 1].second - lookup[i].second);
            if (!(min(dx, dy) == 1 && max(dx, dy) == 2)) {
                return false;
            }
        }
        return true;
    }
};
