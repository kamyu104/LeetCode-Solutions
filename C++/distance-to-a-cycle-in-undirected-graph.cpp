// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

// graph, dfs, bfs
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        return bfs(adj, iter_dfs(adj));
    }

private:
    vector<int> cycle(const vector<int>& parent, int v, int u) {
        vector<int> result = {parent[v], v};
        for (; u != parent[v]; u = parent[u]) {
            result.emplace_back(u);
        }
        return result;
    }

    vector<int> iter_dfs(const vector<vector<int>>& adj) {
        vector<int> stk = {0};
        vector<int> parent(size(adj), -2);
        parent[0] = -1;
        while (!empty(stk)) {
            const int u = stk.back(); stk.pop_back();
            for (const auto& v : adj[u]) {
                if (parent[v] != -2) {
                    if (v == parent[u]) {
                        continue;
                    }
                    return cycle(parent, v, u);
                }
                parent[v] = u;
                stk.emplace_back(v);
            }
        }
        return {};
    }

    vector<int> bfs(const vector<vector<int>>& adj, vector<int> q) {
        vector<int> result(size(adj), -1);
        for (const auto& x : q) {
            result[x] = 0;
        }
        for (int d = 1; !empty(q); ++d) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& v : adj[u]) {
                    if (result[v] != -1) {
                        continue;
                    }
                    result[v] = d;
                    new_q.emplace_back(v);
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
