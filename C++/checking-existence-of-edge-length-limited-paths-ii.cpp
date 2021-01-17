// Time:  ctor:  O(mlogm + m * α(n) + nlogn) ~= O(mlogm + nlogn)
//        query: O(α(n) + logn) ~= O(logn)
// Space: O(nlogn + m)

class DistanceLimitedPathsExist {
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
     : uf_(n), tree_infos_(n) {
        sort(begin(edgeList), end(edgeList),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edgeList) {
            if (!uf_.union_set(edge[0], edge[1])) {
                continue;
            }
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }
        tree_infos_.init(adj);
    }
    
    bool query(int p, int q, int limit) {
        if (uf_.find_set(p) != uf_.find_set(q)) {
            return false;
        }
        return tree_infos_.max_weight(p, q) < limit;
    }

private:
    class TreeInfos {
    public:
        TreeInfos(int n)
         : L_(n)
         , R_(n)
         , P_(n)
         , W_(n)
         , C_(-1) {
            
        }
        
        void init(const unordered_map<int, vector<pair<int, int>>>& adj) {
            for (int i = 0; i < size(L_); ++i) {
                if (L_[i]) {
                    continue;
                }
                flood_fill(adj, i, -1, 0);
            }
        }
        
        bool is_ancestor(int a, int b) {
            return L_[a] <= L_[b] && R_[b] <= R_[a];
        }

        int max_weight(int a, int b) {
            int w = 0;
            if (!is_ancestor(a, b)) {
                w = max(w, binary_lift(a, b));
            }
            if (!is_ancestor(b, a)) {
                w = max(w, binary_lift(b, a));
            }
            return w;
        }

    private:
        int binary_lift(int a, int b) {
            int w = 0;
            for (int i = size(P_[a]) - 1; i >= 0; --i) {  // O(logN)
                if (i < size(P_[a]) && !is_ancestor(P_[a][i], b)) {
                    w = max(w, W_[a][i]);
                    a = P_[a][i];
                }
            }
            return max(w, W_[a][0]);
        }

        void flood_fill(const unordered_map<int, vector<pair<int, int>>>& children,
                        int curr, int parent, int weight) {
            if (parent != -1) {
                W_[curr].emplace_back(weight);
                P_[curr].emplace_back(parent);  // ancestors of the node i
            }
            for (int i = 0; i < size(P_[curr]); ++i) {
                if (i >= size(P_[P_[curr][i]])) {
                    break;
                }
                W_[curr].emplace_back(max(W_[curr][i], W_[P_[curr][i]][i]));
                P_[curr].emplace_back(P_[P_[curr][i]][i]);
            }
            L_[curr] = ++C_; 
            if (children.count(curr)) {
                for (const auto& [child, w] : children.at(curr)) {
                    if (child == parent) {
                        continue;
                    }
                    flood_fill(children, child, curr, w);
                }
            }
            R_[curr] = C_;
        }

        vector<int> L_;
        vector<int> R_;
        vector<vector<int>> P_;
        vector<vector<int>> W_;
        int C_;
    };

    class UnionFind {
    public:
        UnionFind(const int n)
         : set_(n)
         , rank_(n)
         , count_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root == y_root) {
                return false;
            }
            if (rank_[x_root] < rank_[y_root]) {  // Union by rank.
                set_[x_root] = y_root;
            } else if (rank_[x_root] > rank_[y_root]) {
                set_[y_root] = x_root;
            } else {
                set_[y_root] = x_root;
                ++rank_[x_root];
            }
            --count_;
            return true;
        }

        int size() const {
            return count_;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        int count_;
    };

    UnionFind uf_;
    TreeInfos tree_infos_;
};

// Time:  ctor:  O(mlogm + m * α(n) * logm) ~= O(mlogm)
//        query: O(logm + α(n) * logm) ~= O(logm)
// Space: O(n + m * α(n) + m) ~= O(n + m)
class DistanceLimitedPathsExist2 {
public:
    DistanceLimitedPathsExist2(int n, vector<vector<int>>& edgeList)
     : uf_(n) {
        sort(begin(edgeList), end(edgeList),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        for (const auto& edge : edgeList) {
            if (!uf_.union_set(edge[0], edge[1])) {
                continue;
            }
            uf_.snap();
            weights_.emplace_back(edge[2]);
        }
    }
    
    bool query(int p, int q, int limit) {
        int snap_id = distance(cbegin(weights_), lower_bound(cbegin(weights_), cend(weights_), limit)) - 1;
        if (snap_id == -1) {
            return false;
        }
        return uf_.find_set(p, snap_id) == uf_.find_set(q, snap_id);
        
    }

private:
    class VersionedUnionFind {
    public:
        VersionedUnionFind(const int n)
         : set_(n)
         , rank_(n)
         , snap_id_(0) {
             for (int i = 0; i < n; ++i) {
                 set_.set(i, i, snap_id_);
             }
        }

        int find_set(int x, int snap_id) {
            if (set_.get(x, snap_id) != x) {  // Path compression
                set_.set(x, find_set(set_.get(x, snap_id), snap_id), snap_id);
            }
            return set_.get(x, snap_id);
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x, snap_id_), y_root = find_set(y, snap_id_);
            if (x_root == y_root) {
                return false;
            }
            if (rank_.get(x_root, snap_id_) < rank_.get(y_root, snap_id_)) {  // Union by rank.
                set_.set(x_root, y_root, snap_id_);
            } else if (rank_.get(x_root, snap_id_) > rank_.get(y_root, snap_id_)) {
                set_.set(y_root, x_root, snap_id_);
            } else {
                set_.set(y_root, x_root, snap_id_);
                rank_.set(x_root, rank_.get(x_root, snap_id_) + 1, snap_id_);
            }
            return true;
        }

        void snap() {
            ++snap_id_;
        }

    private:
        class SnapshotArray {
        public:
            SnapshotArray(int length) {
            }

            void set(int index, int val, int snap_id) {
                if (!snaps_.count(index)) {
                    snaps_[index][0] = 0;
                }
                snaps_[index][snap_id] = val;
            }

            int get(int index, int snap_id) {
                if (!snaps_.count(index)) {
                    snaps_[index][0] = 0;
                }
                const auto& it = prev(snaps_[index].upper_bound(snap_id));
                return it->second;
            }

        private:
            unordered_map<int, map<int, int>> snaps_;
        };

        SnapshotArray set_;
        SnapshotArray rank_;
        int snap_id_;
    };

    vector<int> weights_;
    VersionedUnionFind uf_;
};
