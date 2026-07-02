// Time:  O((n * p + e * p) * log(n * p))
// Space: O(n * p)

// dijkstra's algorithm
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        static const auto& INF = numeric_limits<int64_t>::max();

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& x : edges) {
            adj[x[0]].emplace_back(x[1], x[2]);
        }
        vector<vector<int64_t>> dist(n, vector<int64_t>(power + 1, INF));
        dist[source][power] = 0;
        using T = tuple<int64_t, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(dist[source][power], -power, source);
        while (!empty(min_heap)) {
            auto [t, p, u] = min_heap.top(); min_heap.pop();
            p = -p;
            if (t > dist[u][p]) {
                continue;
            }
            if (u == target) {
                return {t, p};
            }
            const auto& np = p - cost[u];
            if (np < 0) {
                continue;
            }
            for (const auto& [v, w] : adj[u]) {
                if (t + w >= dist[v][np]) {
                    continue;
                }
                dist[v][np] = t + w;
                min_heap.emplace(dist[v][np], -np, v);
            }
        }
        return {-1, -1};
    }
};
