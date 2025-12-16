// Time:  O(n + elogn)
// Space: O(n + e)

// dijkstra's algorithm
class Solution {
public:
    long long minCostExcludingMax(int n, vector<vector<int>>& edges) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        static const int L = 1;

        vector<vector<pair<int, int>>> adj(n);
        const auto& dijkstra = [&](int src, int dst) {
            vector<vector<int64_t>> dist(L + 1, vector<int64_t>(size(adj), INF));
            const int excl = 0;
            dist[excl][src] = 0;
            using D = tuple<int64_t, int, int>;
            priority_queue<D, vector<D>, greater<D>> min_heap;
            min_heap.emplace(dist[excl][src], src, excl);
            while (!empty(min_heap)) {
                const auto [curr, u, excl] = min_heap.top(); min_heap.pop();
                if (curr != dist[excl][u]) {
                    continue;
                }
                if (u == dst) {
                    break;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (excl <= L - 1 && curr < dist[excl + 1][v]) {
                        dist[excl + 1][v] = curr;
                        min_heap.emplace(dist[excl + 1][v], v, excl + 1);
                    }
                    if (curr + w < dist[excl][v]) {
                        dist[excl][v] = curr + w;
                        min_heap.emplace(dist[excl][v], v, excl);
                    }
                }
            }
            return dist[L][dst];
        };
    
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        return dijkstra(0, n - 1);
    }
};

// Time:  O(n + elogn)
// Space: O(n + e)
// dijkstra's algorithm
class Solution2 {
public:
    long long minCostExcludingMax(int n, vector<vector<int>>& edges) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        static const int L = 1;

        vector<vector<pair<int, int>>> adj(n);
        const auto& dijkstra = [&](int u) {
            vector<int64_t> dist(size(adj), INF);
            dist[u] = 0;
            using D = pair<int64_t, int>;
            priority_queue<D, vector<D>, greater<D>> min_heap;
            min_heap.emplace(dist[u], u);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != dist[u]) {
                    continue;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!(curr + w < dist[v])) {
                        continue;
                    }
                    dist[v] = curr + w;
                    min_heap.emplace(dist[v], v);
                }
            }
            return dist;
        };
    
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& dist1 = dijkstra(0);
        const auto& dist2 = dijkstra(n - 1);
        int64_t result = INF;
        for (const auto& e : edges) {
            result = min(result, min(dist1[e[0]] + dist2[e[1]], dist1[e[1]] + dist2[e[0]]));
        }
        return result;
    }
};
