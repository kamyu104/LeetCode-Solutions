// Time:  O(r * (n + q)), r = max(w for _, _, w in edges)
// Space: O(r * n + q)

// Tarjan's Offline LCA Algorithm
class Solution {
private:
    static const int MAX_W = 26;

public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2] - 1), adj[e[1]].emplace_back(e[0], e[2] - 1);
        }
        unordered_map<int, unordered_set<int>> pairs;
        for (const auto& q : queries) {
            pairs[q[0]].emplace(q[1]), pairs[q[1]].emplace(q[0]);
        }
        TreeInfos tree_infos(adj, pairs);
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& a = queries[i][0], &b = queries[i][1];
            const auto& lca = tree_infos.lca(a, b);
            int mx = 0;
            for (int w = 0; w < MAX_W; ++w) {
                mx = max(mx, tree_infos.count(a, w) + tree_infos.count(b, w) - 2 * tree_infos.count(lca, w));
            }
            result[i] = (tree_infos.depth(a) + tree_infos.depth(b) - 2 * tree_infos.depth(lca)) - mx;
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
        TreeInfos(const vector<vector<pair<int, int>>>& adj, const unordered_map<int, unordered_set<int>>& pairs)
         : D_(size(adj))
         , uf_(size(adj))
         , lookup_(size(adj))
         , CNT_(size(adj))  // added
         , cnt_(MAX_W) {  // added

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

        int count(int a, int w) const {  // added
            return CNT_[a][w];
        }
    
    private:
        void dfs(const vector<vector<pair<int, int>>>& adj,
                 const unordered_map<int, unordered_set<int>>& pairs,
                 int u, int p) {

            D_[u] = (p == -1) ? 1 : D_[p] + 1;
            CNT_[u] = cnt_;  // added
            for (const auto& [v, w] : adj[u]) {
                if (v == p) {
                    continue;
                }
                ++cnt_[w];  // added
                dfs(adj, pairs, v, u);
                --cnt_[w];  // added
                uf_.union_set(v, u);
                uf_.update_ancestor_of_set(u);
            }
            lookup_[u] = true;
            if (!pairs.count(u)) {
                return;
            }
            for (const auto& v : pairs.at(u)) {
                if (!lookup_[v]) {
                    continue;
                }
                lca_[min(u, v)][max(u, v)] = uf_.find_ancestor_of_set(v);
            }
        }

        vector<int> D_;
        UnionFind uf_;
        unordered_map<int, unordered_map<int, int>> lca_;
        vector<bool> lookup_;
        vector<vector<int>> CNT_;  // added
        vector<int> cnt_;  // added
    };
};

// Time:  O(r * (n + q) + nlogn + qlogn), r = max(w for _, _, w in edges)
// Space: O(r * n + nlogn)
// binary lifting (online lca algorithm)
class Solution2 {
private:
    static const int MAX_W = 26;

public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2] - 1), adj[e[1]].emplace_back(e[0], e[2] - 1);
        }
        TreeInfos tree_infos(adj);
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& a = queries[i][0], &b = queries[i][1];
            const auto& lca = tree_infos.lca(a, b);
            int mx = 0;
            for (int w = 0; w < MAX_W; ++w) {
                mx = max(mx, tree_infos.count(a, w) + tree_infos.count(b, w) - 2 * tree_infos.count(lca, w));
            }
            result[i] = (tree_infos.depth(a) + tree_infos.depth(b) - 2 * tree_infos.depth(lca)) - mx;
        }
        return result;
    }

private:
    class TreeInfos {
    public:
        TreeInfos(const vector<vector<pair<int, int>>>& adj)
         : L_(size(adj))
         , R_(size(adj))
         , D_(size(adj))
         , P_(size(adj))
         , C_(-1)
         , CNT_(size(adj))  // added
         , cnt_(MAX_W) {  // added

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
    
        int count(int a, int w) const {  // added
            return CNT_[a][w];
        }

    private:
        void dfs(const vector<vector<pair<int, int>>>& adj, int u, int p) {
            D_[u] = (p == -1) ? 1 : D_[p] + 1;
            if (p != -1) {
                P_[u].emplace_back(p);  // ancestors of the node i
            }
            for (int i = 0; i < size(P_[u]); ++i) {
                if (i >= size(P_[P_[u][i]])) {
                    break;
                }
                P_[u].emplace_back(P_[P_[u][i]][i]);
            }
            L_[u] = ++C_; 
            CNT_[u] = cnt_;  // added
            for (const auto& [v, w] : adj[u]) {
                if (v == p) {
                    continue;
                }
                ++cnt_[w];  // added
                dfs(adj, v, u);
                --cnt_[w];  // added
            }
            R_[u] = C_;
        }

        vector<int> L_;
        vector<int> R_;
        vector<int> D_;
        vector<vector<int>> P_;
        int C_;
        vector<vector<int>> CNT_;  // added
        vector<int> cnt_;  // added
    };
};
