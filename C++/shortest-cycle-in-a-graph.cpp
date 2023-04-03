// Time:  O(n^2)
// Space: O(n + e)

// bfs
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        static const int INF = numeric_limits<int>::max();

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int u) {
            vector<int> dist(n, INF);
            dist[u] = 0;
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[v] == dist[u] - 1) {
                            continue;
                        }
                        if (dist[v] != INF) {
                            return 1 + dist[u] + dist[v];
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return INF;
        };

        int result = INF;
        for (int u = 0; u < n; ++u) {
            result = min(result, bfs(u));
        }
        return result != INF ? result : -1;
    }
};
