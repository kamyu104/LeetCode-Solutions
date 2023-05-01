// Time:  O(n^2)
// Space: O(n^2)

// dijkstra's algorithm in a complete graph (no heap required)
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        static const int INF = numeric_limits<int>::max();

        const auto& id = [&](const auto& x) {
            return static_cast<int64_t>(x.first - 1) * target[1] + (x.second - 1);
        };
        const auto& x_y = [&](const auto& id) {
            return pair(static_cast<int>(id / target[1] + 1), static_cast<int>(id % target[1] + 1));
        };

        const int64_t b = id(pair(start[0], start[1])), t = id(pair(target[0], target[1]));
        unordered_map<int64_t, unordered_map<int64_t, int>> adj;
        unordered_set<int64_t> nodes = {b, t};
        for (const auto& s : specialRoads) {
            const int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3], c = s[4];
            const int64_t u = id(pair(x1, y1)), v = id(pair(x2, y2));
            if (!adj[u].count(v)) {
                adj[u][v] = INF;
            }
            adj[u][v] = min(adj[u][v], c);
            nodes.emplace(u);
            nodes.emplace(v);
        }
        for (const auto& u : nodes) {
            for (const auto& v : nodes) {
                if (!adj[u].count(v)) {
                    adj[u][v] = INF;
                }
                const auto& [x1, y1] = x_y(u); 
                const auto& [x2, y2] = x_y(v);
                adj[u][v] = min(adj[u][v], abs(x2 - x1) + abs(y2 - y1));
            }
        }
        unordered_map<int64_t, int> lookup = {{b, 0}};
        while (!empty(nodes)) {
            pair<int, int64_t> mn = {INF, -1};
            for (const auto& u : nodes) {
                if (lookup.count(u)) {
                    mn = min(mn, pair(lookup[u], u));
                }
            }
            const auto& [d, u] = mn;
            nodes.erase(u);
            if (u == t) {
                return d;
            }
            for (const auto& [v, c] : adj[u]) {
                if (!lookup.count(v) || lookup[v] > d + c) {
                    lookup[v] = d + c;
                }
            }
        }
        return -1;
    }
};
