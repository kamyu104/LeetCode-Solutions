// Time:  O((nlogn + q) * α(n)) ~= O(nlogn + q)
// Space: O(n)

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind union_find(n);
        for (int i = threshold + 1; i <= n; ++i) {
            // https://stackoverflow.com/questions/25905118/finding-big-o-of-the-harmonic-series
            // sum of harmonic series is O(logn)
            for (int j = 2 * i; j <= n; j += i) {
                union_find.union_set(i - 1, j - 1);
            }
        }
        vector<bool> result;
        for (const auto& q : queries) {
            result.emplace_back(union_find.find_set(q[0] - 1) == union_find.find_set(q[1] - 1));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), rank_(n), count_(n) {
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
