// Time:  O(n^2)
// Space: O(n)

// iterative dfs, bfs
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1);
            adj[e[1] - 1].emplace_back(e[0] - 1);
        }
        vector<int> lookup(n, -1);
        const auto& iter_dfs = [&](int u) {
            vector<int> group;
            vector<int> stk = {u};
            lookup[u] = 0;
            while (!empty(stk)) {
                const auto u = stk.back(); stk.pop_back();
                group.emplace_back(u);
                for (const auto& v : adj[u]) {
                    if (lookup[v] != -1) {
                        if (lookup[v] == lookup[u]) {  // odd-length cycle, not bipartite
                            return vector<int>();
                        }
                        continue;
                    }
                    lookup[v] = lookup[u] ^ 1;
                    stk.emplace_back(v);
                }
            }
            return group;
        };
        const auto& bfs = [&](int u) {
            int result = 0;
            vector<bool> lookup(n);
            vector<int> q = {u};
            lookup[u] = true;
            for (; !empty(q); ++result) {
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
            }
            return result;
        };

        int result = 0;
        for (int u = 0; u < n; ++u) {
            if (lookup[u] != -1) {
                continue;
            }
            const auto& group = iter_dfs(u);
            if (empty(group)) {
                return -1;
            }
            int mx = 0;
            for (const auto& u : group) {
                mx = max(mx, bfs(u));
            }
            result += mx;
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// bfs
class Solution2 {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1);
            adj[e[1] - 1].emplace_back(e[0] - 1);
        }
        vector<bool> lookup(n);
        const auto& bfs = [&](int u) {
            vector<int> group = {u};
            vector<int> q = {u};
            lookup[u] = true;
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    group.emplace_back(u);
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
            return group;
        };
        const auto& bfs2 = [&](int u) {
            int result = 0;
            vector<bool> lookup(n);
            unordered_set<int> q = {u};
            lookup[u] = true;
            for (; !empty(q); ++result) {
                unordered_set<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (q.count(v)) {
                            return 0;
                        }
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace(v);
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        int result = 0;
        for (int u = 0; u < n; ++u) {
            if (lookup[u]) {
                continue;
            }
            const auto& group = bfs(u);
            int mx = 0;
            for (const auto& u : group) {
                const int d = bfs2(u);
                if (d == 0) {
                    return -1;
                }
                mx = max(mx, d);
            }
            result += mx;
        }
        return result;
    }
};
