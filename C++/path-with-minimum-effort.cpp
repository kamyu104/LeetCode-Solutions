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
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, 0, 0);
        while (!empty(min_heap)) {
            const auto [d, r, c] = min_heap.top(); min_heap.pop();
            if (r == size(heights) - 1 && c == size(heights[0]) - 1) {
                return d;
            }
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < size(heights) &&
                      0 <= nc && nc < size(heights[0]))) {
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

// Time:  O(m * n * logh)
// Space: O(m * n)
// bi-bfs solution
class Solution2 {
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
 
