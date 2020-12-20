// Time:  O(nlogn + mlogm + n * α(n)) = O(nlogn + mlogm)
// Space: O(n)

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < size(queries); ++i) {
            queries[i].emplace_back(i);
        }
        sort(begin(edgeList), end(edgeList), [&](const auto& a, const auto& b) { return a[2] < b[2]; });
        sort(begin(queries), end(queries), [&](const auto& a, const auto& b) { return a[2] < b[2]; });
        
        UnionFind union_find(n);
        vector<bool> result(size(queries));
        int curr = 0;
        for (const auto &q : queries) {
            int u = q[0], v = q[1], w = q[2], i = q[3];
            for (; curr < size(edgeList) && edgeList[curr][2] < w; ++curr) {
                union_find.union_set(edgeList[curr][0], edgeList[curr][1]);
            }
            result[i] = union_find.find_set(u) == union_find.find_set(v);
        }
        return result;
    }

private:
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
};
