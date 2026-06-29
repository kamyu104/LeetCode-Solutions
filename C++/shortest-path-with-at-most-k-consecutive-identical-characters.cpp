// Time:  O(e * k * log(n * k))
// Space: O(n * k + e)

// dijkstra's algorithms
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        static const auto& INF = numeric_limits<int>::max();

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
        }
        vector<vector<int>> dist(n, vector<int>(k, INF));
        dist[0][0] = 0;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(dist[0][0], 0, 0);
        while (!empty(min_heap)) {
            const auto [d, u, c] = min_heap.top(); min_heap.pop();
            if (d > dist[u][c]) {
                continue;
            }
            if (u == n - 1) {
                return d;
            }
            for (const auto& [v, w] : adj[u]) {
                const auto& nc = labels[v] == labels[u] ? c + 1 : 0;
                if (!(nc < k && d + w < dist[v][nc])) {
                    continue;
                }
                dist[v][nc] = d + w;
                min_heap.emplace(dist[v][nc], v, nc);
            }
        }
        return -1;
    }
};
