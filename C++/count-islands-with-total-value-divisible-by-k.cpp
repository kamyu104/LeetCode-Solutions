// Time:  O(m * n)
// Space: O(m + n)

// bfs, flood fill
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        const auto& bfs = [&](int i, int j) {
            if (!grid[i][j]) {
                return false;
            }
            int total = grid[i][j] % k;
            grid[i][j] = 0;
            vector<pair<int, int>> q = {{i, j}};
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (const auto& [i, j] : q) {
                    for (const auto& [di, dj] : DIRECTIONS) {
                        const int ni = i + di, nj = j + dj;
                        if (!(0 <= ni && ni < size(grid) && 0 <= nj && nj < size(grid[0]) && grid[ni][nj])) {
                            continue;
                        }
                        total = (total + grid[ni][nj]) % k;
                        grid[ni][nj] = 0;
                        new_q.emplace_back(ni, nj);
                    }
                }
                q = move(new_q);
            }
            return total == 0;
        };

        int result = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (bfs(i, j)) {
                    ++result;
                }
            }
        }
        return result;
    }
};
