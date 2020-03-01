// Time:  O(m * n)
// Space: O(m * n)

// A* Search Algorithm without heap
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        pair<int, int> b = {0, 0};
        pair<int, int> t = {grid.size() - 1, grid[0].size() - 1}; 
        return a_star(grid, b, t);
    }

private:
    int a_star(const vector<vector<int>>& grid,
               const pair<int, int>& b,
               const pair<int, int>& t) {

        static const vector<tuple<int, int, int>> directions = {{1, 0, 1}, {2, 0, -1},
                                                                {3, 1, 0}, {4, -1, 0}};
        int f = 0, dh = 1;
        vector<pair<pair<int, int>, int>> closer{{b, 0}}, detour;
        unordered_map<int, int> lookup;
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                f += dh;
                swap(closer, detour);
            }
            const auto [b, d] = closer.back(); closer.pop_back();
            if (b == t) {
                return f;
            }
            for (const auto& [nd, dr, dc] : directions) {
                const pair<int, int>& nb = {b.first + dr, b.second + dc};
                const auto& cost = 1 - (nd == grid[b.first][b.second]);
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      (!lookup.count(nb.first * grid[0].size() + nb.second) ||
                       lookup[nb.first * grid[0].size() + nb.second] > d + cost))) {
                    continue;
                }
                lookup[nb.first * grid[0].size() + nb.second] = d + cost;
                if (!cost) {
                    closer.emplace_back(nb, d);
                } else {
                    detour.emplace_back(nb, d + cost);
                }
            }
        }
        return -1;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid) {
        static const vector<tuple<int, int, int>> directions = {{1, 0, 1}, {2, 0, -1},
                                                                {3, 1, 0}, {4, -1, 0}};
        deque<tuple<int, int, int>> dq = {{0, 0, 0}};
        unordered_map<int, int> lookup = {{0, 0}};
        while (!dq.empty()) {
            const auto [d, r, c] = dq.front(); dq.pop_front();
            if (r == grid.size() - 1 && c == grid[0].size() - 1) {
                return d;
            }
            for (const auto& [nd, dr, dc] : directions) {
                const auto& [nr, nc] = make_pair(r + dr, c + dc);
                const auto& cost = 1 - (nd == grid[r][c]);
                if (!(0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() &&
                      (!lookup.count(nr * grid[0].size() + nc) ||
                       lookup[nr * grid[0].size() + nc] > d + cost))) {
                    continue;
                }
                lookup[nr * grid[0].size() + nc] = d + cost;
                if (cost) {
                    dq.emplace_back(d + cost, nr, nc);
                } else {
                    dq.emplace_front(d, nr, nc);
                }
            }
        }
        return -1;  // never reach here
    }
};
