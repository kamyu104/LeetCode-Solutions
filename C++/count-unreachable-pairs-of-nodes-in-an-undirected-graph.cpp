// Time:  O(n)
// Space: O(n)

// flood fill, bfs, math
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<bool> lookup(n);
        const auto& bfs = [&](int u) {
            vector<int> q = {u};
            lookup[u] = true;
            int64_t result = 1;
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        ++result;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return result;
        };
    
        int64_t result = 0;
        for (int u = 0; u < size(adj); ++u) {
            if (lookup[u]) {
                continue;
            }
            const int64_t cnt = bfs(u);
            result += cnt * (n - cnt);
            n -= cnt;
        }
        return result;
    }
};
