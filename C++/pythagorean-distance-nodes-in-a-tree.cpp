// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        const auto& bfs = [&](int u) {
            vector<int> dist(n, -1);
            dist[u] = 0;
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[v] != -1) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& dist1 = bfs(x);
        const auto& dist2 = bfs(y);
        const auto& dist3 = bfs(z);
        int result = 0;
        for (int u = 0; u < n; ++u) {
            const int64_t a = dist1[u], b = dist2[u], c = dist3[u];
            const auto& mx = max({a, b, c});
            if (a * a + b * b + c * c == 2 * mx * mx) {
                ++result;
            }
        }
        return result;
    }
};
