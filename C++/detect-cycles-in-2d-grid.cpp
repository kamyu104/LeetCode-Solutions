// Time:  O(m * n * α(n)) ~= O(m * n)
// Space: O(m * n)

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        UnionFind union_find(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i && j &&
                    grid[i][j] == grid[i - 1][j] &&
                    grid[i][j] == grid[i][j - 1] &&
                    union_find.find_set(index(grid[0].size(), i - 1, j)) ==
                    union_find.find_set(index(grid[0].size(), i, j - 1))) {
                    return true;
                }
                if (i && grid[i][j] == grid[i - 1][j]) {
                    union_find.union_set(index(grid[0].size(), i - 1, j),
                                         index(grid[0].size(), i, j));
                }
                if (j && grid[i][j] == grid[i][j - 1]) {
                    union_find.union_set(index(grid[0].size(), i, j - 1),
                                         index(grid[0].size(), i, j));
                }
            }
        }
        return false;
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
    
    int index(int n, int i, int j) {
        return i * n + j;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                char val = grid[i][j];
                vector<pair<int, int>> q = {{i, j}};
                while (!q.empty()) {
                    vector<pair<int, int>> new_q;
                    for (const auto& [r, c] : q) {
                        if (!grid[r][c]) {
                            return true;
                        }
                        grid[r][c] = 0;
                        for (const auto& d : directions) {
                            const auto nr = r + d.first;
                            const auto nc = c + d.second;
                            if (!(0 <= nr && nr < grid.size() &&
                                  0 <= nc && nc < grid[0].size() &&
                                  grid[nr][nc] == val)) {
                                continue;
                            }
                            new_q.emplace_back(nr, nc);
                        }
                    }
                    q = move(new_q);
                }
            }
        }
        return false;
    }
};
