// Time:  O(n + qlogh)
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

int binary_search(int left, int right, const auto& check) {
    while (left <= right) {
        const auto& mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
};

// iterative dfs, Tarjan's Offline LCA Algorithm, binary search, prefix sum
class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
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
            vector<int64_t> dist(size(adj));
            vector<int> depth(size(adj));
            vector<int> lca(size(queries));
            vector<int64_t> result(size(queries));
            vector<tuple<int, int, int, int>> stk = {{1, 0, -1, -1}};
            while (!empty(stk)) {
                const auto [step, u, p, i] = stk.back(); stk.pop_back();
                if (step == 1) {
                    for (const auto& i : lookup2[u]) {
                        if (queries[i][0] == queries[i][1]) {
                            lca[i] = u;
                            continue;
                        }
                        result[i] += dist[u];
                        for (const auto& x : queries[i]) {
                            if (lookup[x]) {
                                lca[i] = ancestor[uf.find_set(x)];
                                result[i] -= 2 * dist[lca[i]];
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
                    depth[v] = depth[u] + 1;
                    stk.emplace_back(3, v, u, -1);
                    stk.emplace_back(1, v, -1, -1);
                } else if (step == 3) {
                    uf.union_set(u, p);
                    ancestor[uf.find_set(p)] = p;
                }
            }
            return tuple(result, lca, dist, depth);
        };

        const auto& [result, lca, dist, depth] = iter_dfs();
        const auto& iter_dfs2 = [&]() {
            vector<vector<pair<int, int>>> lookup3(size(adj));
            for (int i = 0; i < size(queries); ++i) {
                const int u = queries[i][0], v = queries[i][1];
                if (2 * (dist[u] - dist[lca[i]]) >= result[i]) {
                    lookup3[u].emplace_back(i, 0);
                } else {
                    lookup3[v].emplace_back(i, 1);
                }
            }
            vector<int> result2(size(queries));
            vector<int> path;
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, i] = stk.back(); stk.pop_back();
                if (step == 1) {
                    path.emplace_back(u);
                    for (const auto& [i, t] : lookup3[u]) {
                        const auto& d = depth[u] - depth[lca[i]];
                        if (t == 0) {
                            const auto& j = binary_search(0, d, [&](const auto& x) {
                                return 2 * (dist[u] - dist[path[size(path) - (x + 1)]]) >= result[i];
                            });
                            result2[i] = path[size(path) - (j + 1)];
                        } else {
                            const auto& l = dist[queries[i][0]] - dist[lca[i]];
                            const auto& j = binary_search(0, d - 1, [&](const auto& x) {
                                return 2 * (l + (dist[path[size(path) - ((d - 1) + 1) + x]] - dist[lca[i]])) >= result[i];
                            });
                            result2[i] = path[size(path) - ((d - 1) + 1) + j];
                        }
                    }
                    stk.emplace_back(3, u, -1);
                    stk.emplace_back(2, u, 0);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& [v, w] = adj[u][i];
                    stk.emplace_back(2, u, i + 1);
                    if (size(path) >= 2 && path[size(path) - 2] == v) {
                        continue;
                    }
                    stk.emplace_back(1, v, -1);
                } else if (step == 3) {
                    path.pop_back();
                }
            }
            return result2;
        };
    
        return iter_dfs2();
    }
};

// Time:  O(n + qlogh)
// Space: O(n + q)
// dfs, Tarjan's Offline LCA Algorithm, binary search, prefix sum
class Solution2 {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
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
        vector<int64_t> dist(size(adj));
        vector<int> depth(size(adj));
        vector<int> lca(size(queries));
        vector<int64_t> result(size(queries));
        const function<void (int)> dfs = [&](int u) {
            for (const auto& i : lookup2[u]) {
                if (queries[i][0] == queries[i][1]) {
                    lca[i] = u;
                    continue;
                }
                result[i] += dist[u];
                for (const auto& x : queries[i]) {
                    if (lookup[x]) {
                        lca[i] = ancestor[uf.find_set(x)];
                        result[i] -= 2 * dist[lca[i]];
                    }
                }
            }
            lookup[u] = true;
            for (const auto& [v, w] : adj[u]) {
                if (lookup[v]) {
                    continue;
                }
                dist[v] = dist[u] + w;
                depth[v] = depth[u] + 1;
                dfs(v);
                uf.union_set(v, u);
                ancestor[uf.find_set(u)] = u;
            }
        };

        dfs(0);
        vector<int> result2(size(queries));
        vector<vector<pair<int, int>>> lookup3(size(adj));
        for (int i = 0; i < size(queries); ++i) {
            const int u = queries[i][0], v = queries[i][1];
            if (2 * (dist[u] - dist[lca[i]]) >= result[i]) {
                lookup3[u].emplace_back(i, 0);
            } else {
                lookup3[v].emplace_back(i, 1);
            }
        }
        vector<int> path;
        const function<void (int)> dfs2 = [&](int u) {
            path.emplace_back(u);
            for (const auto& [i, t] : lookup3[u]) {
                const auto& d = depth[u] - depth[lca[i]];
                if (t == 0) {
                    const auto& j = binary_search(0, d, [&](const auto& x) {
                        return 2 * (dist[u] - dist[path[size(path) - (x + 1)]]) >= result[i];
                    });
                    result2[i] = path[size(path) - (j + 1)];
                } else {
                    const auto& l = dist[queries[i][0]] - dist[lca[i]];
                    const auto& j = binary_search(0, d - 1, [&](const auto& x) {
                        return 2 * (l + (dist[path[size(path) - ((d - 1) + 1) + x]] - dist[lca[i]])) >= result[i];
                    });
                    result2[i] = path[size(path) - ((d - 1) + 1) + j];
                }
            }
            for (const auto& [v, w] : adj[u]) {
                if (size(path) >= 2 && path[size(path) - 2] == v) {
                    continue;
                }
                dfs2(v);
            }
            path.pop_back();
        };
    
        dfs2(0);
        return result2;
    }
};
