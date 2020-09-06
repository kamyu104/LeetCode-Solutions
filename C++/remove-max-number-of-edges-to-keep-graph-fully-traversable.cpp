// Time:  O(n + m * α(n)) ~= O(n + m)
// Space: O(n)

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int result = 0;
        UnionFind union_find_a(n), union_find_b(n);
        for (const auto& edge : edges) {
            int t = edge[0], i = edge[1], j = edge[2];
            if (t != 3) {
                continue;
            }
            bool a = union_find_a.union_set(i - 1, j - 1);
            bool b = union_find_b.union_set(i - 1, j - 1);
            if (!a && !b) {
                ++result;
            }
        }
        for (const auto& edge : edges) {
            int t = edge[0], i = edge[1], j = edge[2];
            if (t == 1) {
                if (!union_find_a.union_set(i - 1, j - 1)) {
                    ++result;
                }
            } else if (t == 2) {
                if (!union_find_b.union_set(i - 1, j - 1)) {
                    ++result;
                }
            }
        }
        return union_find_a.size() == 1 && union_find_b.size() == 1 ? result : -1;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), size_(n) {
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
            set_[max(x_root, y_root)] = min(x_root, y_root);
            --size_;
            return true;
        }

        int size() const {
            return size_;
        }

    private:
        vector<int> set_;
        int size_;
    };
};
