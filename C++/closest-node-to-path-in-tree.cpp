// Time:  O(n + q)
// Space: O(n + q)

// Tarjan's Offline LCA Algorithm
class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        unordered_map<int, unordered_set<int>> pairs;
        for (const auto& q : query) {
            pairs[q[0]].emplace(q[1]), pairs[q[1]].emplace(q[0]);
            pairs[q[0]].emplace(q[2]), pairs[q[2]].emplace(q[0]);
            pairs[q[1]].emplace(q[2]), pairs[q[2]].emplace(q[1]);
        }
        TreeInfos tree_infos(adj, pairs);
        vector<int> result;
        for (const auto& q : query) {
            vector<int> candidates = {tree_infos.lca(q[0], q[1]),
                                      tree_infos.lca(q[0], q[2]),
                                      tree_infos.lca(q[1], q[2])};
            result.emplace_back(*max_element(cbegin(candidates), cend(candidates),
                                             [&tree_infos](const auto& a, const auto& b) {
                                                 return tree_infos.depth(a) < tree_infos.depth(b);
                                             }));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , ancestor_(n) {
            iota(set_.begin(), set_.end(), 0);
            iota(ancestor_.begin(), ancestor_.end(), 0);  // added
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
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

    int find_ancestor_of_set(int x) {  // added
        return ancestor_[find_set(x)];
    }

    void update_ancestor_of_set(int x) {  // added
        ancestor_[find_set(x)] = x;
    }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> ancestor_;  // added
    };
    
    class TreeInfos {
    public:
        TreeInfos(const vector<vector<int>>& adj, const unordered_map<int, unordered_set<int>>& pairs)
         : D_(size(adj))
         , uf_(size(adj))
         , lookup_(size(adj)) {

             dfs(adj, pairs, 0, -1);
        }

        int lca(int a, int b) const {
            if (a > b) {
                swap(a, b);
            }
            return lca_.at(a).at(b);
        }

        int depth(int a) const {
            return D_[a];
        }
    
    private:
        void dfs(const vector<vector<int>>& adj,
                 const unordered_map<int, unordered_set<int>>& pairs,
                 int curr, int parent) {

            D_[curr] = (parent == -1) ? 1 : D_[parent] + 1;
            for (const auto& child : adj[curr]) {
                if (child == parent) {
                    continue;
                }
                dfs(adj, pairs, child, curr);
                uf_.union_set(child, curr);
                uf_.update_ancestor_of_set(curr);
            }
            lookup_[curr] = true;
            if (!pairs.count(curr)) {
                return;
            }
            for (const auto& v : pairs.at(curr)) {
                if (!lookup_[v]) {
                    continue;
                }
                lca_[min(curr, v)][max(curr, v)] = uf_.find_ancestor_of_set(v);
            }
        }

        vector<int> D_;
        UnionFind uf_;
        unordered_map<int, unordered_map<int, int>> lca_;
        vector<bool> lookup_;
    };
};

// Time:  O(nlogn + qlogn)
// Space: O(nlogn)
// binary lifting (online lca algorithm)
class Solution2 {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        TreeInfos tree_infos(adj);
        vector<int> result;
        for (const auto& q : query) {
            vector<int> candidates = {tree_infos.lca(q[0], q[1]),
                                      tree_infos.lca(q[0], q[2]),
                                      tree_infos.lca(q[1], q[2])};
            result.emplace_back(*max_element(cbegin(candidates), cend(candidates),
                                             [&tree_infos](const auto& a, const auto& b) {
                                                 return tree_infos.depth(a) < tree_infos.depth(b);
                                             }));
        }
        return result;
    }

private:
    class TreeInfos {
    public:
        TreeInfos(const vector<vector<int>>& adj)
         : L_(size(adj))
         , R_(size(adj))
         , D_(size(adj))
         , P_(size(adj))
         , C_(-1) {

             dfs(adj, 0, -1);
        }
        
        bool is_ancestor(int a, int b) const {
            return L_[a] <= L_[b] && R_[b] <= R_[a];
        }

        int lca(int a, int b) const {
            if (D_[a] > D_[b]) {
                swap(a, b);
            }
            if (is_ancestor(a, b)) {
                return a;
            }
            for (int i = size(P_[a]) - 1; i >= 0; --i) {  // O(logN)
                if (i < size(P_[a]) && !is_ancestor(P_[a][i], b)) {
                    a = P_[a][i];
                }
            }
            return P_[a][0];
        }

        int depth(int a) const {
            return D_[a];
        }
    
    private:
        void dfs(const vector<vector<int>>& adj, int curr, int parent) {
            D_[curr] = (parent == -1) ? 1 : D_[parent] + 1;
            if (parent != -1) {
                P_[curr].emplace_back(parent);  // ancestors of the node i
            }
            for (int i = 0; i < size(P_[curr]); ++i) {
                if (i >= size(P_[P_[curr][i]])) {
                    break;
                }
                P_[curr].emplace_back(P_[P_[curr][i]][i]);
            }
            L_[curr] = ++C_; 
            for (const auto& child : adj[curr]) {
                if (child == parent) {
                    continue;
                }
                dfs(adj, child, curr);
            }
            R_[curr] = C_;
        }

        vector<int> L_;
        vector<int> R_;
        vector<int> D_;
        vector<vector<int>> P_;
        int C_;
    };
};

// Time:  O(n + q * h)
// Space: O(n)
// lca
class Solution3 {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        TreeInfos tree_infos(adj);
        vector<int> result;
        for (const auto& q : query) {
            vector<int> candidates = {tree_infos.lca(q[0], q[1]),
                                      tree_infos.lca(q[0], q[2]),
                                      tree_infos.lca(q[1], q[2])};
            result.emplace_back(*max_element(cbegin(candidates), cend(candidates),
                                             [&tree_infos](const auto& a, const auto& b) {
                                                 return tree_infos.depth(a) < tree_infos.depth(b);
                                             }));
        }
        return result;
    }

private:
    class TreeInfos {
    public:
        TreeInfos(const vector<vector<int>>& adj)
         : D_(size(adj))
         , P_(size(adj)) {

             dfs(adj, 0, -1);
        }

        int lca(int a, int b) const {
            while (D_[a] > D_[b]) {
                a = P_[a];
            }
            while (D_[a] < D_[b]) {
                b = P_[b];
            }
            while (a != b) {
                a = P_[a];
                b = P_[b];
            }
            return a;
        }

        int depth(int a) const {
            return D_[a];
        }
    
    private:
        void dfs(const vector<vector<int>>& adj, int curr, int parent) {
            D_[curr] = (parent == -1) ? 1 : D_[parent] + 1;
            P_[curr] = parent;  // ancestors of the node i
            for (const auto& child : adj[curr]) {
                if (child == parent) {
                    continue;
                }
                dfs(adj, child, curr);
            }
        }

        vector<int> D_;
        vector<int> P_;
    };
};

// Time:  O(n^2 + q * n)
// Space: O(n^2)
// bfs
class Solution4 {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&adj](int root) {
            vector<int> dist(size(adj), size(adj));
            vector<int> q = {root};
            dist[root] = 0;
            for (int d = 0; !empty(q); ++d) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (d + 1 >= dist[v]) {
                            continue;
                        }
                        dist[v] = d + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };
        vector<vector<int>> dist(n);
        for (int i = 0; i < n; ++i) {
            dist[i] = bfs(i);
        }
        vector<int> result;
        for (const auto& q : query) {
            int x = q[1];
            for (int u = q[0]; u != q[1];) {
                if (dist[q[2]][u] < dist[q[2]][x]) {
                    x = u;
                }
                for (const auto& v : adj[u]) {
                    if (dist[v][q[1]] < dist[u][q[1]]) {
                        u = v;
                        break;
                    }
                }
            }
            result.emplace_back(x);
        }
        return result;
    }
};

// Time:  O(n^2 + q * n)
// Space: O(n^2)
// bfs
class Solution_TLE {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&adj](int root) {
            vector<int> dist(size(adj), size(adj));
            vector<int> q = {root};
            dist[root] = 0;
            for (int d = 0; !empty(q); ++d) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (d + 1 >= dist[v]) {
                            continue;
                        }
                        dist[v] = d + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };
        vector<vector<int>> dist(n);
        for (int i = 0; i < n; ++i) {
            dist[i] = bfs(i);
        }
        vector<int> result;
        for (const auto& q : query) {
            int j = -1;
            for (int i = 0; i < n; ++i) {
                if (dist[q[0]][q[2]] + dist[q[2]][q[1]] - 2 * dist[q[2]][i] == dist[q[0]][i] + dist[i][q[1]]) {
                    if (j == -1 || dist[q[2]][j] < dist[q[2]][i]) {
                        j = i;
                    }
                }
            }
            result.emplace_back(j);
        }
        return result;
    }
};
