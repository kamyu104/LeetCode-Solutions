// Time:  O(n * m)
// Space: O(min(n, m))

// combinatorics
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int n = size(grid), m = size(grid[0]);
        const auto& get = [&](int i, int j) {
            return n < m ? grid[i][j] : grid[j][i];
        };

        const int mn = min(n, m), mx = max(n, m);
        vector<int> cnt1(mn);
        for (int i = 0; i < mn; ++i) {
            for (int j = 0; j < mx; ++j) {
                cnt1[i] += get(i, j);
            }
        }
        int64_t result = 0;
        for (int j = 0; j < mx; ++j) {
            int cnt2 = 0;
            for (int i = 0; i < mn; ++i) {
                cnt2 += get(i, j);
            }
            for (int i = 0; i < mn; ++i) {
                if (get(i, j)) {
                    result += (cnt1[i] - 1ll) * (cnt2 - 1ll);
                }
            }
        }
        return result;
    }
};

// Time:  O(n * m)
// Space: O(n + m)
// combinatorics
class Solution2 {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int n = size(grid), m = size(grid[0]);
        vector<int> cnt1(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt1[i] += grid[i][j];
            }
        }
        vector<int> cnt2(m);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                cnt2[j] += grid[i][j];
            }
        }
        int64_t result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    result += (cnt1[i] - 1ll) * (cnt2[j] - 1ll);
                }
            }
        }
        return result;
    }
};

// Time:  O(n * m)
// Space: O(min(n, m))
// freq table
class Solution3 {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int n = size(grid), m = size(grid[0]);
        const auto& get = [&](int i, int j) {
            return n < m ? grid[i][j] : grid[j][i];
        };
    
        const int mn = min(n, m), mx = max(n, m);
        const auto& count = [&](int first, int last) {
            int64_t result = 0;
            int d = last > first ? 1 : (last < first ? -1 : 0);
            vector<int> cnt(mn);
            for (int j = first; j != last + d; j += d) {
                int c = 0;
                for (int i = 0; i < size(cnt); ++i) {
                    c += get(i, j);
                }
                for (int i = 0; i < size(cnt); ++i) {
                    if (get(i, j) == 0) {
                        continue;
                    }
                    result += cnt[i];
                    cnt[i] += c - 1;
                }
            }
            return result;
        };

        return count(0, mx - 1) + count(mx - 1, 0);
    }
};
