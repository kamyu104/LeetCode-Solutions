// Time:  O(nlog*n) ~= O(n), n is the length of the positions
// Space: O(n)

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind union_find(edges.size() + 1);
        for (const auto& edge : edges) {
            if (!union_find.union_set(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), count_(n) {
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
                set_[min(x_root, y_root)] = max(x_root, y_root);
                --count_;
                return true;
            }

            int length() const {
                return count_;
            }

        private:
            vector<int> set_;
            int count_;
    };
};
