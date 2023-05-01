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

        const int64_t s = id(pair(start[0], start[1])), t = id(pair(target[0], target[1]));
        unordered_map<int64_t, vector<pair<int64_t, int>>> adj;
        adj[t];
        for (const auto& s : specialRoads) {
            const int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3], c = s[4];
            const int64_t u = id(pair(x1, y1)), v = id(pair(x2, y2));
            adj[u].emplace_back(v, c);
        }
        unordered_map<int64_t, int> dist = {{s, 0}};
        unordered_set<int64_t> lookup;
        while (size(lookup) != size(dist)) {
            pair<int, int64_t> mn = {INF, -1};
            for (const auto& [u, d] : dist) {
                if (!lookup.count(u)) {
                    mn = min(mn, pair(d, u));
                }
            }
            const auto& [d, u] = mn;
            lookup.emplace(u);
            if (u == t) {
                return d;
            }
            for (const auto& [v, c] : adj[u]) {
                if (!dist.count(v) || dist[v] > d + c) {
                    dist[v] = d + c;
                }
            }
            const auto& [x1, y1] = x_y(u);
            for (const auto& [v, _] : adj) {
                const auto& [x2, y2] = x_y(v);
                if (!dist.count(v) || dist[v] > d + abs(x2 - x1) + abs(y2 - y1)) {
                    dist[v] = d + abs(x2 - x1) + abs(y2 - y1);
                }
            }
        }
        return -1;
    }
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// dijkstra's algorithm
class Solution2 {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        static const int INF = numeric_limits<int>::max();

        const auto& id = [&](const auto& x) {
            return static_cast<int64_t>(x.first - 1) * target[1] + (x.second - 1);
        };
        const auto& x_y = [&](const auto& id) {
            return pair(static_cast<int>(id / target[1] + 1), static_cast<int>(id % target[1] + 1));
        };

        const int64_t s = id(pair(start[0], start[1])), t = id(pair(target[0], target[1]));
        unordered_map<int64_t, vector<pair<int64_t, int>>> adj;
        adj[t];
        unordered_set<int64_t> nodes = {s, t};
        for (const auto& s : specialRoads) {
            const int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3], c = s[4];
            const int64_t u = id(pair(x1, y1)), v = id(pair(x2, y2));
            adj[u].emplace_back(v, c);
        }
        priority_queue<pair<int, int64_t>, vector<pair<int, int64_t>>, greater<pair<int, int64_t>>> min_heap;
        min_heap.emplace(0, s);
        unordered_map<int64_t, int> dist = {{s, 0}};
        while (!empty(min_heap)) {
            const auto [d, u] = min_heap.top(); min_heap.pop();
            if (d > dist[u]) {
                continue;
            }
            if (u == t) {
                return d;
            }
            for (const auto& [v, c] : adj[u]) {
                if (!dist.count(v) || dist[v] > d + c) {
                    dist[v] = d + c;
                    min_heap.emplace(dist[v], v);
                }
            }
            const auto& [x1, y1] = x_y(u);
            for (const auto& [v, _] : adj) {
                const auto& [x2, y2] = x_y(v);
                if (!dist.count(v) || dist[v] > d + abs(x2 - x1) + abs(y2 - y1)) {
                    dist[v] = d + abs(x2 - x1) + abs(y2 - y1);
                    min_heap.emplace(dist[v], v);
                }
            }
        }
        return -1;
    }
};
