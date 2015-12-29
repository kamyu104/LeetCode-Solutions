// Time:  O(nlog*n) ~= O(n), n is the length of the positions
// Space: O(n)

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UnionFind union_find(n);
        for (const auto& e : edges) {
            union_find.union_set(e.first, e.second);
        }
        return union_find.length();
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), count_(n) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            void union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root != y_root) {
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                    --count_;
                }
            }

            int length() const {
                return count_;
            }

        private:
            vector<int> set_;
            int count_;
    };
};
