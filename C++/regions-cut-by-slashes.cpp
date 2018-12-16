// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        UnionFind union_find(grid.size() * grid.size() * 4);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i) {
                    union_find.union_set(index(grid.size(), i - 1, j, S),
                                         index(grid.size(),i, j, N));
                }
                if (j) {
                    union_find.union_set(index(grid.size(), i, j - 1, E),
                                         index(grid.size(), i, j, W));
                }
                if (grid[i][j] != '/') {
                    union_find.union_set(index(grid.size(), i, j, N),
                                         index(grid.size(), i, j, E));
                    union_find.union_set(index(grid.size(), i, j, S),
                                         index(grid.size(), i, j, W));
                }
                if (grid[i][j] != '\\') {
                    union_find.union_set(index(grid.size(), i, j, W),
                                         index(grid.size(), i, j, N));
                    union_find.union_set(index(grid.size(), i, j, E),
                                         index(grid.size(), i, j, S));
                }
            }
        }
        return union_find.size();
    }
    
private:
    enum NODES {N, E, S, W};
    
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

            void union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root != y_root) {
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                    --count_;
                }
            }

            int size() const {
                return count_;
            }

        private:
            vector<int> set_;
            int count_;
    };
    
    int index(int n, int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
};
