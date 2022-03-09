// Time:  O(|V| * |E|)
// Space: O(|V| + |E|)

// dfs
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
        }
        vector<vector<int>> result(n);
        for (int u = 0; u < n; ++u) {
            iter_dfs(adj, u, &result);
        }
        return result;
    }

private:
    void iter_dfs(const vector<vector<int>>& adj,
                  int i,
                  vector<vector<int>> *result) {

        vector<bool> lookup(size(adj));
        vector<int> stk = {i};
        while (!empty(stk)) {
            const auto u = stk.back(); stk.pop_back();
            for (const auto& v: adj[u]) {
                if (lookup[v]) {
                    continue;
                }
                lookup[v] = true;
                stk.emplace_back(v);
                (*result)[v].emplace_back(i);
            }
        }
    }
};

// Time:  O(|V| * |E| * log(|V| * |E|))
// Space: O(|V| + |E|)
// bfs
class Solution2 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[1]].emplace_back(e[0]);
        }
        vector<vector<int>> result(n);
        for (int u = 0; u < n; ++u) {
            bfs(adj, u, &result);
        }
        return result;
    }

private:
    void bfs(const vector<vector<int>>& adj,
             int i,
             vector<vector<int>> *result) {

        vector<bool> lookup(size(adj));
        vector<int> q = {i};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& v: adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    lookup[v] = true;
                    new_q.emplace_back(v);
                    (*result)[i].emplace_back(v);
                }
            }
            q = move(new_q);
        }
        sort(begin((*result)[i]), end((*result)[i]));
    }
};

// Time:  O(|V| * |E| * log(|V| * |E|))
// Space: O(|V| + |E|)
// topological sort
class Solution3 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> lookup(n);
        vector<int> in_degree(n);
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            ++in_degree[e[1]];
            lookup[e[1]].emplace(e[0]);
        }
        vector<int> q;
        for (int u = 0; u < n; ++u) {
            if (!in_degree[u]) {
                q.emplace_back(u);
            }
        }
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& v : adj[u]) {
                    for (const auto& x : lookup[u]) {
                        lookup[v].emplace(x);
                    }
                    if (!--in_degree[v]) {
                        new_q.emplace_back(v);
                    }
                }
            }
            q = move(new_q);
        }
        vector<vector<int>> result;
        for (const auto& x : lookup) {
            vector<int> tmp(cbegin(x), cend(x));
            sort(begin(tmp), end(tmp));
            result.emplace_back(move(tmp));
        }
        return result;
    }
};
