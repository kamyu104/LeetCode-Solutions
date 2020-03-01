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
        vector<pair<int, int>> closer = {b}, detour;
        unordered_set<int> lookup;
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                f += dh;
                swap(closer, detour);
            }
            const auto b = closer.back(); closer.pop_back();
            if (b == t) {
                return f;
            }
            if (lookup.count(b.first * grid[0].size() + b.second)) {
                continue;
            }
            lookup.emplace(b.first * grid[0].size() + b.second);
            for (const auto& [nd, dr, dc] : directions) {
                const pair<int, int>& nb = {b.first + dr, b.second + dc};
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      !lookup.count(nb.first * grid[0].size() + nb.second))) {
                    continue;
                }
                if (nd == grid[b.first][b.second]) {
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
            if (lookup[r * grid[0].size() + c] < d) {
                continue;
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
