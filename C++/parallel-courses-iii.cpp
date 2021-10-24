// Time:  O(|V| + |E|)
// Space: O(|E|)

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> in_degree(n);
        for (const auto& relation : relations) {
            adj[relation[0] - 1].emplace_back(relation[1] - 1);
            ++in_degree[relation[1] - 1];
        }
        vector<int> q;
        vector<int> dist(n);
        for (int u = 0; u < n; ++u) {
            if (in_degree[u]) {
                continue;
            }
            q.emplace_back(u);
            dist[u] = time[u];
        }
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& v : adj[u]) {
                    dist[v] = max(dist[v], dist[u] + time[v]);
                    --in_degree[v];
                    if (!in_degree[v]) {
                        new_q.emplace_back(v);
                    }
                }
            }
            q = move(new_q);
        }
        return *max_element(cbegin(dist), cend(dist));
    }
};
