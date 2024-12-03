// Time:  O(n + m)
// Space: O(n + m)

// bfs
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& bfs = [](const auto& adj) {
            vector<int> lookup(size(adj), -1);
            vector<pair<int, int>> q = {{0, -1}};
            for (int parity = 0; !empty(q); parity ^= 1) {
                vector<pair<int, int>> new_q;
                for (const auto& [u, p] : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v] != -1) {
                            continue;
                        }
                        lookup[v] = parity ^ 1;
                        new_q.emplace_back(v, u);
                    }
                }
                q = move(new_q);
            }
            const int cnt = accumulate(cbegin(lookup), cend(lookup), 0);
            vector<int> result(size(adj));
            for (int u = 0; u < size(adj); ++u) {
                result[u] = lookup[u] ? cnt : size(adj) - cnt;
            }
            return result;
        };

        const auto& find_adj = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            return adj;
        };

        const auto& adj2 = find_adj(edges2);
        const int mx = ranges::max(bfs(adj2));
        const auto& adj1 = find_adj(edges1);
        vector<int> result(size(adj1));
        const auto& ret = bfs(adj1);
        for (int u = 0; u < size(adj1); ++u) {
            result[u] = mx + ret[u];
        }
        return result;
    }
};
