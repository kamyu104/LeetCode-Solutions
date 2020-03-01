// Time:  O(m * n)
// Space: O(m * n)

// A* Search Algorithm without heap
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const pair<int, int> b = {0, 0}, t = {grid.size() - 1, grid[0].size() - 1}; 
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
// 0-1 bfs solution
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid) {
        static const vector<tuple<int, int, int>> directions = {{1, 0, 1}, {2, 0, -1},
                                                                {3, 1, 0}, {4, -1, 0}};
        const pair<int, int> b = {0, 0}, t = {grid.size() - 1, grid[0].size() - 1}; 
        deque<pair<pair<int, int>, int>> dq = {{b, 0}};
        unordered_map<int, int> lookup = {{b.first * grid[0].size() + b.second, 0}};
        while (!dq.empty()) {
            const auto [b, d] = dq.front(); dq.pop_front();
            if (b == t) {
                return d;
            }
            if (lookup[b.first * grid[0].size() + b.second] < d) {
                continue;
            }
            for (const auto& [nd, dr, dc] : directions) {
                const auto& nb = make_pair(b.first + dr, b.second + dc);
                const auto& cost = nd != grid[b.first][b.second] ? 1 : 0;
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      (!lookup.count(nb.first * grid[0].size() + nb.second) ||
                       lookup[nb.first * grid[0].size() + nb.second] > d + cost))) {
                    continue;
                }
                lookup[nb.first * grid[0].size() + nb.second] = d + cost;
                if (!cost) {
                    dq.emplace_front(nb, d);
                } else {
                    dq.emplace_back(nb, d + cost);
                }
            }
        }
        return -1;  // never reach here
    }
};
