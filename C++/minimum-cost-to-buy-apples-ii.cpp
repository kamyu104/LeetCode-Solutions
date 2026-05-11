// Time:  O(n * (n + elogn))
// Space: O(n + e)

// dijkstra's algorithm
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        static const auto& INF = numeric_limits<int64_t>::max();

        vector<vector<pair<int, int64_t>>> adj(2 * n);
        const auto& dijkstra = [&](int start, int target) {
            vector<int64_t> best(size(adj), INF);
            best[start] = 0;
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(best[start], start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                if (u == target) {
                    return curr;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return INF;
        };

        for (const auto& r : roads) {
            const auto u = r[0], v = r[1];
            const int64_t c = r[2], t = r[3];
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
            adj[u + n].emplace_back(v + n, c * t);
            adj[v + n].emplace_back(u + n, c * t);
        }
        for (int i = 0; i < n; ++i) {
            adj[i].emplace_back(i + n , prices[i]);
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = dijkstra(i, i + n);
        }
        return result;
    }
};

// Time:  O(n * (n + elogn))
// Space: O(n + e)
// dijkstra's algorithm
class Solution2 {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        static const auto& INF = numeric_limits<int64_t>::max();

        vector<vector<vector<pair<int, int64_t>>>> adj(2, vector<vector<pair<int, int64_t>>>(n));
        const auto& dijkstra = [&](const auto& adj, int start) {
            vector<int64_t> best(size(adj), INF);
            best[start] = 0;
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(best[start], start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };

        for (const auto& r : roads) {
            const auto u = r[0], v = r[1];
            const int64_t c = r[2], t = r[3];
            adj[0][u].emplace_back(v, c);
            adj[0][v].emplace_back(u, c);
            adj[1][u].emplace_back(v, c * t);
            adj[1][v].emplace_back(u, c * t);
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            vector<vector<int64_t>> dist = {dijkstra(adj[0], i), dijkstra(adj[1], i)};
            int64_t mn = INF;
            for (int j = 0; j < n; ++j) {
                if (dist[0][j] != INF && dist[1][j] != INF) {
                    mn = min(mn, dist[0][j] + prices[j] + dist[1][j]);
                }
            }
            result[i] = mn;
        }
        return result;
    }
};
