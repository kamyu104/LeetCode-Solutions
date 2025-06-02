// Time:  O(n)
// Space: O(n)

// bfs, combinatorics
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1);
            adj[e[1] - 1].emplace_back(e[0] - 1);
        }
        const auto& bfs = [&]() {
            int d = -1;
            vector<bool> lookup(size(adj));
            lookup[0] = true;
            vector<int> q = {0};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
                ++d;
            }
            return d;
        };

        int result = 1;
        for (int d = bfs() - 1; d; --d) {
            result = (result * 2) % MOD;
        }
        return result;
    }
};
