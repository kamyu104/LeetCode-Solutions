// Time:  ctor:  O(mlogm + m * α(n) * logm) ~= O(mlogm)
//        query: O(logm + α(n) * logm) ~= O(logm)
// Space: O(n + m * α(n) + m) ~= O(n + m)

class UnionFind {
public:
    UnionFind(const int n)
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

class DistanceLimitedPathsExist {
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
     : uf_(n) {
        sort(begin(edgeList), end(edgeList),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        for (const auto& edge : edgeList) {
            uf_.union_set(edge[0], edge[1]);
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
    vector<int> weights_;
    UnionFind uf_;
};
