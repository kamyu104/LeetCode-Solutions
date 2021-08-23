// Time:  O(m * n * log(m * n))
// Space: O(m * n)

// Dijkstra algorithm solution
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};

        using T = tuple<int, int, int>;
        vector<vector<int>> dist(size(heights), vector<int>(size(heights[0]), numeric_limits<int>::max()));
        dist[0][0] = 0;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, 0, 0);
        vector<vector<int>> lookup(size(heights), vector<int>(size(heights[0])));
        while (!empty(min_heap)) {
            const auto [d, r, c] = min_heap.top(); min_heap.pop();
            if (lookup[r][c]) {
                continue;
            }
            lookup[r][c] = true;
            if (r == size(heights) - 1 && c == size(heights[0]) - 1) {
                return d;
            }
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < size(heights) &&
                      0 <= nc && nc < size(heights[0]) &&
                      !lookup[nr][nc])) {
                    continue;
                }
                int nd = max(d, abs(heights[nr][nc] - heights[r][c]));
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    min_heap.emplace(nd, nr, nc);
                }
            }
        }
        return -1;
    }
};

// Time:  O(m * n * log(m * n) + m * n * α(m * n)) = O(m * n * log(m * n))
// Space: O(m * n)
// union find solution
class Solution2 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<tuple<int, int, int>> diffs;
        for (int i = 0; i < size(heights); ++i) {
            for (int j = 0; j < size(heights[0]); ++j) {
                if (i > 0) {
                    diffs.emplace_back(abs(heights[i][j] - heights[i - 1][j]), 
                                       index(size(heights[0]), i - 1, j),
                                       index(size(heights[0]), i, j));
                }
                if (j > 0) {
                    diffs.emplace_back(abs(heights[i][j] - heights[i][j - 1]),
                                       index(size(heights[0]), i, j - 1),
                                       index(size(heights[0]), i, j));
                }
            }
        }
        sort(begin(diffs), end(diffs));
        UnionFind union_find(size(heights) * size(heights[0]));
        for (const auto& [d, i, j] : diffs) {
            if (union_find.union_set(i, j)) {
                if (union_find.find_set(index(size(heights[0]), 0, 0)) ==
                    union_find.find_set(index(size(heights[0]), size(heights) - 1, size(heights[0]) - 1))) {
                    return d;
                }
            }
        }
        return 0;
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
    
    int index(int n, int i, int j) {
        return i * n + j;
    }
};

// Time:  O(m * n * logh)
// Space: O(m * n)
// bi-bfs solution
class Solution3 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const int MAX_H = 1e6;
        int left = 0, right = MAX_H;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(heights, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<vector<int>>& heights, int x) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};

        vector<vector<int>> lookup(size(heights), vector<int>(size(heights[0])));
        unordered_set<pair<int, int>, PairHash<int>> left({{0, 0}});
        unordered_set<pair<int, int>, PairHash<int>> right({{size(heights) - 1, size(heights[0]) - 1}});
        while (!empty(left)) {
            for (const auto& [r, c] : left) {
                lookup[r][c] = true;
            }
            unordered_set<pair<int, int>, PairHash<int>> new_left;
            for (const auto& [r, c] : left) {
                if (right.count(pair(r, c))) {
                    return true;
                }
                for (const auto& [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (!(0 <= nr && nr < size(heights) &&
                          0 <= nc && nc < size(heights[0]) &&
                          abs(heights[nr][nc] - heights[r][c]) <= x &&
                          !lookup[nr][nc])) {
                        continue;
                    }
                    new_left.emplace(nr, nc);
                }
            }
            left = move(new_left);
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return false;
    }
    
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
 };

// Time:  O(m * n * logh)
// Space: O(m * n)
// bfs solution
class Solution4 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const int MAX_H = 1e6;
        int left = 0, right = MAX_H;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(heights, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<vector<int>>& heights, int x) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};

        queue<pair<int, int>> q({{0, 0}});
        vector<vector<int>> lookup(size(heights), vector<int>(size(heights[0])));
        while (!empty(q)) {
            const auto [r, c] = q.front(); q.pop();
            if (r == size(heights) - 1 && c == size(heights[0]) - 1) {
                return true;
            }
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < size(heights) &&
                      0 <= nc && nc < size(heights[0]) &&
                      abs(heights[nr][nc] - heights[r][c]) <= x &&
                      !lookup[nr][nc])) {
                    continue;
                }
                lookup[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
        return false;
    }
    
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
 };
 
// Time:  O(m * n * logh)
// Space: O(m * n)
// dfs solution
class Solution5 {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const int MAX_H = 1e6;
        int left = 0, right = MAX_H;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(heights, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<vector<int>>& heights, int x) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};

        vector<pair<int, int>> stk({{0, 0}});
        vector<vector<int>> lookup(size(heights), vector<int>(size(heights[0])));
        while (!empty(stk)) {
            const auto [r, c] = stk.back(); stk.pop_back();
            if (r == size(heights) - 1 && c == size(heights[0]) - 1) {
                return true;
            }
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < size(heights) &&
                      0 <= nc && nc < size(heights[0]) &&
                      abs(heights[nr][nc] - heights[r][c]) <= x &&
                      !lookup[nr][nc])) {
                    continue;
                }
                lookup[nr][nc] = true;
                stk.emplace_back(nr, nc);
            }
        }
        return false;
    }
    
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
 };
