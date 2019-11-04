// Time:  O(m * n * log(m * n))
// Space: O(m * n)

// binary search + dfs solution
class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<int> vals;
        const auto ceil = min(A[0][0], A.back().back());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j] <= ceil) {
                    vals.emplace_back(A[i][j]);
                }
            }
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int left = 0, right = vals.size() - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            unordered_set<pair<int, int>, PairHash<int>> lookup;
            if (!check(A, vals[mid], 0, 0, &lookup)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
       }
        return vals[right];
    }
    
private:
    bool check(const vector<vector<int>>& A,
               int val, int r, int c,
               unordered_set<pair<int, int>, PairHash<int>> *lookup) {

        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0},
                                                          {0, -1}, {-1, 0}};        
        if (r == A.size() - 1 && c == A[0].size() - 1) {
            return true;
        }
        lookup->emplace(r, c);
        for (const auto& d : directions) {
            const auto nr = r + d.first;
            const auto nc = c + d.second;
            if (0 <= nr && nr < A.size() &&
                0 <= nc && nc < A[0].size() &&
                !lookup->count({nr, nc}) &&
                A[nr][nc] >= val &&
                check(A, val, nr, nc, lookup)) {
                return true;
            }
        }
        return false;
    }
};

// Time:  O(m * n * log(m * n))
// Space: O(m * n)
// Dijkstra algorithm solution
class Solution2 {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        static const vector<pair<int, int>> directions = {{0, 1}, {1, 0},
                                                          {0, -1}, {-1, 0}};
        using P = tuple<int, int, int>;
        priority_queue<P> max_heap;
        max_heap.emplace(A[0][0], 0, 0);
        unordered_set<pair<int, int>, PairHash<int>> lookup = {{0, 0}};
        while (!max_heap.empty()) {
            int i, r, c;
            tie(i, r, c) = max_heap.top(); max_heap.pop();
            if (r == A.size() - 1 && c == A[0].size() - 1) {
                return i;
            }
            for (const auto& d : directions) {
                const auto nr = r + d.first;
                const auto nc = c + d.second;
                if (0 <= nr && nr < A.size() &&
                    0 <= nc && nc < A[0].size() &&
                    !lookup.count({nr, nc})) {
                    max_heap.emplace(min(i, A[nr][nc]), nr, nc);
                    lookup.emplace(nr, nc);
                }
            }
        }
        return -1;
    }
};
