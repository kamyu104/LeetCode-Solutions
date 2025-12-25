// Time:  O(n)
// Space: O(n)

// tree diameter, bfs
class Solution {
public:
    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int u) {
            vector<bool> lookup(size(adj));
            lookup[u] = true;
            vector<int> q = {u}, new_q;
            while (!empty(q)) {
                new_q.clear();
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                swap(q, new_q);
            }
            return new_q;
        };

        string result(n, '0');
        const auto& far = bfs(0);
        for (const auto& u : far) {
            result[u] = '1';
        }
        for (const auto& u : bfs(far[0])) {
            result[u] = '1';
        }
        return result;
    }
};
