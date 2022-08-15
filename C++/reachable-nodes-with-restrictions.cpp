// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int result = 0;
        vector<bool> lookup(n);
        for (const auto& x : restricted) {
            lookup[x] = true;
        }
        vector<int> q = {0};
        lookup[0] = true;
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                ++result;
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
        return result;
    }
};
