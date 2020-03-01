// Time:  O(m * n)
// Space: O(m * n)

class Solution {
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
                       d + cost < lookup[nr * grid[0].size() + nc]))) {
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
