// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          { 0, -1}, { 0, 1},
                                                          { 1, -1}, { 1, 0}, { 1, 1}};
        int result = 0;
        queue<pair<int, int>> q({{0, 0}});
        while (!q.empty()) {
            ++result;
            queue<pair<int, int>> next_depth;
            while (!q.empty()) {
                int i, j;
                tie(i, j) = q.front(); q.pop();
                if (0 <= i && i < grid.size() &&
                    0 <= j && j < grid[0].size() &&
                    !grid[i][j]) {
                    grid[i][j] = 1;
                    if (i == grid.size() - 1 && j == grid.size() - 1) {
                        return result;
                    }
                    for (const auto& dir : directions) {
                        next_depth.emplace(i + dir.first, j + dir.second);
                    }
                }
            }
            q = move(next_depth);
        }
        return -1;
    }
};
