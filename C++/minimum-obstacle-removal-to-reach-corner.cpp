// Time:  O(m * n)
// Space: O(m * n)

// A* Search Algorithm without heap
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const pair<int, int> b = {0, 0}, t = {grid.size() - 1, grid[0].size() - 1}; 
        return a_star(grid, b, t);
    }

private:
    int a_star(const vector<vector<int>>& grid,
               const pair<int, int>& b,
               const pair<int, int>& t) {

        static const vector<pair<int, int>> directions = {{0, 1}, {0, -1},
                                                          {1, 0}, {-1, 0}};
        int f = 0, dh = 1;
        vector<pair<int, int>> closer = {b}, detour;
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                f += dh;
                swap(closer, detour);
            }
            const auto b = closer.back(); closer.pop_back();
            if (b == t) {
                return f;
            }
            if (lookup[b.first][b.second]) {
                continue;
            }
            lookup[b.first][b.second] = true;
            for (const auto& [dr, dc] : directions) {
                const pair<int, int>& nb = {b.first + dr, b.second + dc};
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      !lookup[nb.first][nb.second])) {
                    continue;
                }
                if (!grid[b.first][b.second]) {
                    closer.emplace_back(nb);
                } else {
                    detour.emplace_back(nb);
                }
            }
        }
        return -1;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// 0-1 bfs solution
class Solution2 {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> directions = {{0, 1}, {0, -1},
                                                          {1, 0}, {-1, 0}};
        const pair<int, int> b = {0, 0}, t = {grid.size() - 1, grid[0].size() - 1}; 
        deque<pair<pair<int, int>, int>> dq = {{b, 0}};
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        while (!dq.empty()) {
            const auto [b, d] = dq.front(); dq.pop_front();
            if (b == t) {
                return d;
            }
            if (lookup[b.first][b.second]) {
                continue;
            }
            lookup[b.first][b.second] = true;
            for (const auto& [dr, dc] : directions) {
                const auto& nb = make_pair(b.first + dr, b.second + dc);
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      !lookup[nb.first][nb.second])) {
                    continue;
                }
                if (!grid[nb.first][nb.second]) {
                    dq.emplace_front(nb, d);
                } else {
                    dq.emplace_back(nb, d + 1);
                }
            }
        }
        return -1;  // never reach here
    }
};
