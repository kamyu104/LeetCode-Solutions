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
            UnionFind(const int n) : set(n) {
                iota(set.begin(), set.end(), 0);
                count_ = n;
            }

            int find_set(int x) {
               if (set[x] != x) {
                   set[x] = find_set(set[x]);  // Path compression.
               }
               return set[x];
            }

            void union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root != y_root) {
                    set[min(x_root, y_root)] = max(x_root, y_root);
                    --count_;
                }
            }

            int length() const {
                return count_;
            }

        private:
            vector<int> set;
            int count_;
    };
};
