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

// iterative dfs, Tarjan's Offline LCA Algorithm, combinatorics
class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1);
            adj[e[1] - 1].emplace_back(e[0] - 1);
        }
        const auto& iter_dfs = [&]() {
            vector<bool> lookup(size(adj));
            vector<vector<int>> lookup2(size(adj));
            for (int i = 0; i < size(queries); ++i) {
                for (const auto& x : queries[i]) {
                    lookup2[x - 1].emplace_back(i);
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
                        if (queries[i][0] == queries[i][1]) {
                            continue;
                        }
                        result[i] += dist[u];
                        for (const auto& x : queries[i]) {
                            if (lookup[x - 1]) {
                                result[i] -= 2 * dist[ancestor[uf.find_set(x - 1)]];
                            }
                        }
                    }
                    lookup[u] = true;
                    stk.emplace_back(2, u, -1, 0);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, -1, i + 1);
                    if (lookup[v]) {
                        continue;
                    }
                    dist[v] = dist[u] + 1;
                    stk.emplace_back(3, v, u, -1);
                    stk.emplace_back(1, v, -1, -1);
                } else if (step == 3) {
                    uf.union_set(u, p);
                    ancestor[uf.find_set(p)] = p;
                }
            }
            return result;
        };

        const auto& result = iter_dfs();
        vector<int> POW2(size(adj) - 1, 1);
        for (int i = 0; i + 1 < size(POW2); ++i) {
            POW2[i + 1] = (POW2[i] * 2) % MOD;
        }
        vector<int> ret(size(result));
        for (int i = 0; i < size(ret); ++i) {
            ret[i] = result[i] - 1 >= 0 ? POW2[result[i] - 1] : 0;
        }
        return ret;
    }
};

// dfs, Tarjan's Offline LCA Algorithm, combinatorics
class Solution2 {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace_back(e[1] - 1);
            adj[e[1] - 1].emplace_back(e[0] - 1);
        }
        vector<bool> lookup(size(adj));
        vector<vector<int>> lookup2(size(adj));
        for (int i = 0; i < size(queries); ++i) {
            for (const auto& x : queries[i]) {
                lookup2[x - 1].emplace_back(i);
            }
        }
        UnionFind uf(size(adj));
        vector<int> ancestor(size(adj));
        iota(begin(ancestor), end(ancestor), 0);
        vector<int> dist(size(adj));
        vector<int> result(size(queries));
        const function<void (int)> dfs = [&](int u) {
            for (const auto& i : lookup2[u]) {
                if (queries[i][0] == queries[i][1]) {
                    continue;
                }
                result[i] += dist[u];
                for (const auto& x : queries[i]) {
                    if (lookup[x - 1]) {
                        result[i] -= 2 * dist[ancestor[uf.find_set(x - 1)]];
                    }
                }
            }
            lookup[u] = true;
            for (const auto& v : adj[u]) {
                if (lookup[v]) {
                    continue;
                }
                dist[v] = dist[u] + 1;
                dfs(v);
                uf.union_set(v, u);
                ancestor[uf.find_set(u)] = u;
            }
        };

        dfs(0);
        vector<int> POW2(size(adj) - 1, 1);
        for (int i = 0; i + 1 < size(POW2); ++i) {
            POW2[i + 1] = (POW2[i] * 2) % MOD;
        }
        vector<int> ret(size(result));
        for (int i = 0; i < size(ret); ++i) {
            ret[i] = result[i] - 1 >= 0 ? POW2[result[i] - 1] : 0;
        }
        return ret;
    }
};
