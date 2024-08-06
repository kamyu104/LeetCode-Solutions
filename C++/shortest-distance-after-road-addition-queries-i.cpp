// Time:  O(n^2)
// Space: O(n^2)

// bfs
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int u = 0; u + 1 < n; ++u) {
            adj[u].emplace_back(u + 1);
        }
        vector<int> dist(n);
        iota(begin(dist), end(dist), 0);
        const auto& bfs = [&](int u, int v) {
            adj[u].emplace_back(v);
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[u] + 1 >= dist[v]) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist[n - 1];
        };

        vector<int> result;
        result.reserve(n);
        for (const auto& q : queries) {
            result.emplace_back(bfs(q[0], q[1]));
        }
        return result;
    }
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// dijkstra's algorithm
class Solution2 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (int u = 0; u + 1 < n; ++u) {
            adj[u].emplace_back(u + 1, 1);
        }
        vector<int> dist(n);
        iota(begin(dist), end(dist), 0);
        const auto& dijkstra = [&](int u, int v) {
            adj[u].emplace_back(v, 1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(dist[u], u);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > dist[u]) {
                    continue;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (curr + w >= dist[v]) {
                        continue;
                    }
                    dist[v] = curr + w;
                    min_heap.emplace(dist[v], v);
                }
            }
            return dist[n - 1];
        };

        vector<int> result;
        result.reserve(n);
        for (const auto& q : queries) {
            result.emplace_back(dijkstra(q[0], q[1]));
        }
        return result;
    }
};
