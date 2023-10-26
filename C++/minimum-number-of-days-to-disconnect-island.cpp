// Time:  O((m * n) * log(m * n))
// Space: O(m * n)

// flood fill, persistent union find
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        const int R = size(grid), C = size(grid[0]);
        if (count_islands(grid) != 1) {
            return 0;
        }
    
        PersistentUnionFind uf(R * C);
        vector<int> lookup(R * C);
        const auto& merge = [&](int i) {
            const int r = i / C, c = i % C;
            for (const auto& [dr, dc] : DIRECTIONS) {
                const int nr = r + dr, nc = c + dc;
                const int ni = nr * C + nc;
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == grid[r][c] && lookup[ni]) {
                    uf.union_set(i, ni);
                }
            }
        };

        const auto& check = [&](int i) {
            const int r = i / C, c = i % C;
            if (grid[r][c] == 0) {
                return false;
            }
            unordered_set<int> lookup;
            for (const auto& [dr, dc] : DIRECTIONS) {
                const int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == grid[r][c]) {
                    lookup.emplace(uf.find_set(nr * C + nc));
                }
            }
            return size(lookup) != 1;
        };

        const function<bool (int, int)> dfs = [&](int left, int right) {
            if (left == right) {
                return check(left);
            }
            const int mid = left + (right - left) / 2;
            int l1 = left, r1 = mid, l2 = mid + 1, r2 = right;
            for (int _ = 0; _ < 2; ++_) {
                uf.snapshot();
                for (int i = l1; i <= r1; ++i) {
                    lookup[i] = true;
                    merge(i);
                }
                if (dfs(l2, r2)) {
                    return true;
                }
                for (int i = l1; i <= r1; ++i) {
                    lookup[i] = false;
                }
                uf.rollback();
                swap(l1, l2), swap(r1, r2);
            };
            return false;
        };

        return dfs(0, R * C - 1) ? 1 : 2;
    }

private:
    int count_islands(const vector<vector<int>>& grid) {
        vector<vector<int>> lookup(grid.size(), vector<int>(grid[0].size()));
        int islands_cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 || lookup[i][j]) {
                    continue;
                }
                ++islands_cnt;
                floodfill(grid, i, j, &lookup);
            }
        }
        return islands_cnt;
    }

    void floodfill(const vector<vector<int>>& grid, int i, int j, vector<vector<int>> *lookup) {
        static const vector<pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<pair<int, int>> stk = {{i, j}};
        (*lookup)[i][j] = 1;
        while (!stk.empty()) {
            auto [i, j] = stk.back(); stk.pop_back();
            for (const auto& [di, dj] : DIRECTIONS) {
                const auto& [ni, nj] = pair(i + di, j + dj);
                if (!(0 <= ni && ni < grid.size() &&
                      0 <= nj && nj < grid[0].size() &&
                      grid[ni][nj] &&
                      !(*lookup)[ni][nj])) {
                    continue;
                }
                (*lookup)[ni][nj] = 1;
                stk.emplace_back(ni, nj);
            }
        }
    }

    class PersistentUnionFind {
    public:
        PersistentUnionFind(int n)
         : set_(n)
         , size_(n) {
            iota(begin(set_), end(set_), 0);
        }

        int find_set(int x) {
            vector<int> stk;
            while (set_[x] != x) {  // path compression
                stk.emplace_back(x);
                x = set_[x];
            }
            while (!empty(stk)) {
                const int y = stk.back(); stk.pop_back();
                undos_.emplace_back(~y, set_[y]);  // added
                set_[y] = x;
            }
            return x;
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (size_[x] > size_[y]) {
                swap(x, y);
            }
            undos_.emplace_back(x, y);  // added
            set_[x] = y;  // Union by size.
            size_[y] += size_[x];
            return true;
        }

        void snapshot() {  // added
            snapshots_.emplace_back(size(undos_));
        }
    
        void rollback() {  // added
            const int cnt = snapshots_.back(); snapshots_.pop_back();
            while (size(undos_) != cnt) {
                const auto [x, y] = undos_.back(); undos_.pop_back();
                if (x >= 0) {
                    size_[y] -= size_[x];
                    set_[x] = x;
                } else {
                    set_[~x] = y;
                }
            }
        }

    private:
        vector<int> set_;
        vector<int> size_;
        vector<pair<int, int>> undos_;
        vector<int> snapshots_;
    };
};

// Time:  O(m^2 * n^2)
// Space: O(m * n)
// flood fill
class Solution2 {
public:
    int minDays(vector<vector<int>>& grid) {
        if (count_islands(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                grid[i][j] = 0;
                int islands_cnt = count_islands(grid);
                grid[i][j] = 1;
                if (islands_cnt != 1) {
                    return 1;
                }
            }
        }
        return 2;
    }

private:
    int count_islands(const vector<vector<int>>& grid) {
        vector<vector<int>> lookup(grid.size(), vector<int>(grid[0].size()));
        int islands_cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0 || lookup[i][j]) {
                    continue;
                }
                ++islands_cnt;
                floodfill(grid, i, j, &lookup);
            }
        }
        return islands_cnt;
    }

    void floodfill(const vector<vector<int>>& grid, int i, int j, vector<vector<int>> *lookup) {
        static const vector<pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<pair<int, int>> stk = {{i, j}};
        (*lookup)[i][j] = 1;
        while (!stk.empty()) {
            auto [i, j] = stk.back(); stk.pop_back();
            for (const auto& [di, dj] : DIRECTIONS) {
                const auto& [ni, nj] = pair(i + di, j + dj);
                if (!(0 <= ni && ni < grid.size() &&
                      0 <= nj && nj < grid[0].size() &&
                      grid[ni][nj] &&
                      !(*lookup)[ni][nj])) {
                    continue;
                }
                (*lookup)[ni][nj] = 1;
                stk.emplace_back(ni, nj);
            }
        }
    }
};
