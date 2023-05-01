// Time:  O(m * n)
// Space: O(1)

// bfs
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const auto& bfs = [&](int i, int j) {
            int result = grid[i][j];
            vector<pair<int ,int>> q = {{i, j}};
            grid[i][j] = 0;
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (const auto& [i, j] : q) {
                    for (const auto& [di, dj] : DIRECTIONS) {
                        const int ni = i + di, nj = j + dj;
                        if (!(0 <= ni && ni < size(grid) &&
                              0 <= nj && nj < size(grid[0]) &&
                              grid[ni][nj])) {
                            continue;
                        }
                        result += grid[ni][nj];
                        grid[ni][nj] = 0;
                        new_q.emplace_back(ni, nj);
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        int result = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j]) {
                    result = max(result, bfs(i, j));
                }
            }
        }
        return result;
    }
};
