// Time:  O(n + q)
// Space: O(n + q)

class UnionFind {
public:
    UnionFind(int n)
        : set_(n)
        , rank_(n) { 
        iota(begin(set_), end(set_), 0);
    }

    int find_set(int x) {
        vector<int> stk;
        while (set_[x] != x) {  // path compression
            stk.emplace_back(x);
            x = set_[x];
        }
        return x;
    }

    bool union_set(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x == y) {
            return false;
        }
        if (rank_[x] > rank_[y]) {
            swap(x, y);
        }
        set_[x] = y;  // Union by rank.
        if (rank_[x] == rank_[y]) {
            ++rank_[y];
        }
        return true;
    }

private:
    vector<int> set_;
    vector<int> rank_;
};

// iterative dfs, Tarjan's Offline LCA Algorithm
class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& iter_dfs = [&]() {
            vector<bool> lookup(size(adj));
            vector<vector<int>> lookup2(size(adj));
            for (int i = 0; i < size(queries); ++i) {
                for (const auto& x : queries[i]) {
                    lookup2[x].emplace_back(i);
                }
            }
            UnionFind uf(size(adj));
            vector<int> ancestor(size(adj));
            iota(begin(ancestor), end(ancestor), 0);
            vector<int> dist(size(adj));
            vector<int> result(size(queries));
            vector<tuple<int, int, int, int>> stk = {{1, 0, -1, -1}};
            while (!empty(stk)) {
                const auto [step, u, p, i] = stk.back(); stk.pop_back();
                if (step == 1) {
                    for (const auto& i : lookup2[u]) {
                        result[i] += dist[u];
                        for (const auto& x : queries[i]) {
                            if (lookup[x]) {
                                result[i] -= dist[ancestor[uf.find_set(x)]];
                            }
                        }
                    }
                    lookup[u] = true;
                    stk.emplace_back(2, u, -1, 0);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& [v, w] = adj[u][i];
                    stk.emplace_back(2, u, -1, i + 1);
                    if (lookup[v]) {
                        continue;
                    }
                    dist[v] = dist[u] + w;
                    stk.emplace_back(3, v, u, -1);
                    stk.emplace_back(1, v, -1, -1);
                } else if (step == 3) {
                    uf.union_set(u, p);
                    ancestor[uf.find_set(p)] = p;
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n + q)
// Space: O(n + q)
// dfs, Tarjan's Offline LCA Algorithm
class Solution2 {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<bool> lookup(size(adj));
        vector<vector<int>> lookup2(size(adj));
        for (int i = 0; i < size(queries); ++i) {
            for (const auto& x : queries[i]) {
                lookup2[x].emplace_back(i);
            }
        }
        UnionFind uf(size(adj));
        vector<int> ancestor(size(adj));
        iota(begin(ancestor), end(ancestor), 0);
        vector<int> dist(size(adj));
        vector<int> result(size(queries));
        const function<void (int)> dfs = [&](int u) {
            for (const auto& i : lookup2[u]) {
                result[i] += dist[u];
                for (const auto& x : queries[i]) {
                    if (lookup[x]) {
                        result[i] -= dist[ancestor[uf.find_set(x)]];
                    }
                }
            }
            lookup[u] = true;
            for (const auto& [v, w] : adj[u]) {
                if (lookup[v]) {
                    continue;
                }
                dist[v] = dist[u] + w;
                dfs(v);
                uf.union_set(v, u);
                ancestor[uf.find_set(u)] = u;
            }
        };

        dfs(0);
        return result;
    }
};
