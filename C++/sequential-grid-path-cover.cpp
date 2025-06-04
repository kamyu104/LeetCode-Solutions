// Time:  O(m * n * 3^(m * n))
// Space: O(m * n)

// backtracking
class Solution {
public:
    vector<vector<int>> findPath(vector<vector<int>>& grid, int k) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> result;
        const function<bool (int, int, int)> backtracking = [&](int i, int j, int curr) {
            const int v = grid[i][j];
            if (v && v != curr) {
                return false;
            }
            grid[i][j] = -1;
            result.emplace_back(vector<int>{i, j});
            if (size(result) == size(grid) * size(grid[0])) {
                return true;
            }
            const int new_curr = v == curr ? curr + 1 : curr;
            for (const auto& [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < size(grid) && 0 <= nj && nj < size(grid[0]) && grid[ni][nj] != -1)) {
                    continue;
                }
                if (backtracking(ni, nj, new_curr)) {
                    return true;
                }
            }
            result.pop_back();
            grid[i][j] = v;
            return false;
        };

        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (backtracking(i, j, 1)) {
                    return result;
                }
            }
        }
        return result;
    }
};
