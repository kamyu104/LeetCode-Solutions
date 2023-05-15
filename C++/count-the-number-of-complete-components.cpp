// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> lookup(n);
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int u) {
            if (lookup[u]) {
                return false;
            }
            int v_cnt = 0, e_cnt = 0;
            lookup[u] = true;
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                v_cnt += size(q);
                for (const auto& u : q) {
                    e_cnt += size(adj[u]);
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return v_cnt * (v_cnt - 1) == e_cnt;
        };

        int result = 0;
        for (int u = 0; u < n; ++u) {
            result += bfs(u);
        }
        return result;
    }
};
