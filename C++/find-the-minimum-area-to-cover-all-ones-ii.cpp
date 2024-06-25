// Time:  O(n * m * log(max(n, m)) + max(n, m)^2)
// Space: O(n * m * log(max(n, m)))

// sparse table
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        vector<SparseTable> st_min_i, st_max_i, st_min_j, st_max_j;
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            const int min_r = min(st_min_i[(size(grid) - 1) - min_i].query(min_j, max_j), max_i + 1);
            const int max_r = max(st_max_i[max_i].query(min_j, max_j), min_i - 1);
            const int min_c = min(st_min_j[(size(grid[0]) - 1) - min_j].query(min_i, max_i), max_j + 1);
            const int max_c = max(st_max_j[max_j].query(min_i, max_i), min_j - 1);
            return (max_r - min_r + 1) * (max_c-min_c + 1);
        };

        vector<int> curr;
        curr.assign(size(grid[0]), size(grid));
        for (int i = size(grid) - 1; i >= 0; --i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j]) {
                    curr[j] = i;
                }
            }
            st_min_i.emplace_back(SparseTable(curr, [&](int i, int j) { return min(i, j); }));
        }
        curr.assign(size(grid[0]), -1);
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j]) {
                    curr[j] = i;
                }
            }
            st_max_i.emplace_back(SparseTable(curr, [&](int i, int j) { return max(i, j); }));
        }
        curr.assign(size(grid), size(grid[0]));
        for (int j = size(grid[0]) - 1; j >= 0; --j) {
            for (int i = 0; i < size(grid); ++i) {
                if (grid[i][j]) {
                    curr[i] = j;
                }
            }
            st_min_j.emplace_back(SparseTable(curr, [&](int i, int j) { return min(i, j); }));
        }
        curr.assign(size(grid), -1);
        for (int j = 0; j < size(grid[0]); ++j) {
            for (int i = 0; i < size(grid); ++i) {
                if (grid[i][j]) {
                    curr[i] = j;
                }
            }
            st_max_j.emplace_back(SparseTable(curr, [&](int i, int j) { return max(i, j); }));
        }
        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int j = i + 1; j < size(grid); ++j) {
                const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(i + 1, size(grid) - 1, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, 0, j);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int i = j + 1; i < size(grid[0]); ++i) {
                const int b = minimumArea(0, size(grid) - 1, j + 1, i);
                const int c = minimumArea(0, size(grid) - 1, i + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, 0, j);
                result = min(result, a + b + c);
            }
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            st.assign(k + 1, vector<int>(n));
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int query(int L, int R) const {
            const int i = __lg(R - L + 1);
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(1)
        }
    
    private:
        vector<vector<int>> st;
        const function<int (int, int)>& fn;
    };
};

// Time:  O(n * m * log(max(n, m)) + max(n, m)^2)
// Space: O(n * m * log(max(n, m)))
// sparse table
class Solution2 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& rotate = [](const auto& grid) {
            vector<vector<int>> result(size(grid[0]), vector<int>(size(grid)));
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    result[j][(size(grid) - 1) - i] = grid[i][j];
                }
            }
            return result;
        };

        vector<SparseTable> st_min_i, st_max_i, st_min_j, st_max_j;
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            const int min_r = min(st_min_i[(size(grid) - 1) - min_i].query(min_j, max_j), max_i + 1);
            const int max_r = max(st_max_i[max_i].query(min_j, max_j), min_i - 1);
            const int min_c = min(st_min_j[(size(grid[0]) - 1) - min_j].query(min_i, max_i), max_j + 1);
            const int max_c = max(st_max_j[max_j].query(min_i, max_i), min_j - 1);
            return (max_r - min_r + 1) * (max_c-min_c + 1);
        };
    
        vector<int> curr;
        int result = numeric_limits<int>::max();
        for (int _ = 0; _ < 4; ++_) {
            st_min_i.clear();
            curr.assign(size(grid[0]), size(grid));
            for (int i = size(grid) - 1; i >= 0; --i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    if (grid[i][j]) {
                        curr[j] = i;
                    }
                }
                st_min_i.emplace_back(SparseTable(curr, [&](int i, int j) { return min(i, j); }));
            }
            st_max_i.clear();
            curr.assign(size(grid[0]), -1);
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    if (grid[i][j]) {
                        curr[j] = i;
                    }
                }
                st_max_i.emplace_back(SparseTable(curr, [&](int i, int j) { return max(i, j); }));
            }
            st_min_j.clear();
            curr.assign(size(grid), size(grid[0]));
            for (int j = size(grid[0]) - 1; j >= 0; --j) {
                for (int i = 0; i < size(grid); ++i) {
                    if (grid[i][j]) {
                        curr[i] = j;
                    }
                }
                st_min_j.emplace_back(SparseTable(curr, [&](int i, int j) { return min(i, j); }));
            }
            st_max_j.clear();
            curr.assign(size(grid), -1);
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int i = 0; i < size(grid); ++i) {
                    if (grid[i][j]) {
                        curr[i] = j;
                    }
                }
                st_max_j.emplace_back(SparseTable(curr, [&](int i, int j) { return max(i, j); }));
            }
            for (int i = 0; i < size(grid); ++i) {
                const int a = minimumArea(0, i, 0, size(grid[0]) - 1);
                for (int j = 0; j < size(grid[0]); ++j) {
                    const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                    const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
                for (int j = i + 1; j < size(grid); ++j) {
                    const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                    const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
            }
            grid = rotate(grid);
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            st.assign(k + 1, vector<int>(n));
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int query(int L, int R) const {
            const int i = __lg(R - L + 1);
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(1)
        }
    
    private:
        vector<vector<int>> st;
        const function<int (int, int)>& fn;
    };
};

// Time:  O(max(n, m)^2 * log(max(n, m)))
// Space: O(1)
// prefix sum, binary search
class Solution3 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };
        
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            const auto& count = [&](int x1, int y1, int x2, int y2) {
                int cnt = grid[x2][y2];
                if (x1 - 1 >= 0) {
                    cnt -= grid[x1 - 1][y2];
                }
                if (y1 - 1 >= 0) {
                    cnt -= grid[x2][y1 - 1];
                }
                if (x1 - 1 >= 0 && y1 - 1 >= 0) {
                    cnt += grid[x1 - 1][y1 - 1];
                }
                return cnt;
            };

            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            const int min_r = binary_search(min_i, max_i, [&](int i) { return count(min_i, min_j, i, max_j); });
            const int max_r = binary_search_right(min_i, max_i, [&](int i) { return count(i, min_j, max_i, max_j); });
            const int min_c = binary_search(min_j, max_j, [&](int j) { return count(min_i, min_j, max_i, j); });
            const int max_c = binary_search_right(min_j, max_j, [&](int j) { return count(min_i, j, max_i, max_j); });
            return (max_r - min_r + 1) * (max_c-min_c + 1);
        };

        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if (j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] -= grid[i - 1][j - 1];
                }
            }
        }
        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int j = i + 1; j < size(grid); ++j) {
                const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(i + 1, size(grid) - 1, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, 0, j);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int i = j + 1; i < size(grid[0]); ++i) {
                const int b = minimumArea(0, size(grid) - 1, j + 1, i);
                const int c = minimumArea(0, size(grid) - 1, i + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, 0, j);
                result = min(result, a + b + c);
            }
        }
        return result;
    }
};

// Time:  O(max(n, m)^2 * log(max(n, m)))
// Space: O(n * m)
// prefix sum, binary search
class Solution4 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& rotate = [](const auto& grid) {
            vector<vector<int>> result(size(grid[0]), vector<int>(size(grid)));
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    result[j][(size(grid) - 1) - i] = grid[i][j];
                }
            }
            return result;
        };
    
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        vector<vector<int>> prefix;
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            const auto& count = [&](int x1, int y1, int x2, int y2) {
                int cnt = prefix[x2][y2];
                if (x1 - 1 >= 0) {
                    cnt -= prefix[x1 - 1][y2];
                }
                if (y1 - 1 >= 0) {
                    cnt -= prefix[x2][y1 - 1];
                }
                if (x1 - 1 >= 0 && y1 - 1 >= 0) {
                    cnt += prefix[x1 - 1][y1 - 1];
                }
                return cnt;
            };

            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            const int min_r = binary_search(min_i, max_i, [&](int i) { return count(min_i, min_j, i, max_j); });
            const int max_r = binary_search_right(min_i, max_i, [&](int i) { return count(i, min_j, max_i, max_j); });
            const int min_c = binary_search(min_j, max_j, [&](int j) { return count(min_i, min_j, max_i, j); });
            const int max_c = binary_search_right(min_j, max_j, [&](int j) { return count(min_i, j, max_i, max_j); });
            return (max_r - min_r + 1) * (max_c-min_c + 1);
        };

        int result = numeric_limits<int>::max();
        for (int _ = 0; _ < 4; ++_) {
            prefix.assign(size(grid), vector<int>(size(grid[0])));
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    prefix[i][j] = grid[i][j];
                    if (i - 1 >= 0) {
                        prefix[i][j] += prefix[i - 1][j];
                    }
                    if (j - 1 >= 0) {
                        prefix[i][j] += prefix[i][j - 1];
                    }
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        prefix[i][j] -= prefix[i - 1][j - 1];
                    }
                }
            }
            for (int i = 0; i < size(grid); ++i) {
                const int a = minimumArea(0, i, 0, size(grid[0]) - 1);
                for (int j = 0; j < size(grid[0]); ++j) {
                    const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                    const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
                for (int j = i + 1; j < size(grid); ++j) {
                    const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                    const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
            }
            grid = rotate(grid);
        }
        return result;
    }
};

// Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
// Space: O(1)
// brute force
class Solution5 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            int min_r = max_i + 1;
            int max_r = min_i - 1;
            int min_c = max_j + 1;
            int max_c = min_j - 1;
            for (int i = min_i; i <= max_i; ++i) {
                for (int j = min_j; j <= max_j; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int j = i + 1; j < size(grid); ++j) {
                const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(i + 1, size(grid) - 1, 0, size(grid[0]) - 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, 0, j);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            for (int i = j + 1; i < size(grid[0]); ++i) {
                const int b = minimumArea(0, size(grid) - 1, j + 1, i);
                const int c = minimumArea(0, size(grid) - 1, i + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
            a = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
            for (int i = 0; i < size(grid); ++i) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, 0, j);
                result = min(result, a + b + c);
            }
        }
        return result;
    }
};

// Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
// Space: O(n * m)
// brute force
class Solution6 {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& rotate = [](const auto& grid) {
            vector<vector<int>> result(size(grid[0]), vector<int>(size(grid)));
            for (int i = 0; i < size(grid); ++i) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    result[j][(size(grid) - 1) - i] = grid[i][j];
                }
            }
            return result;
        };
    
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            if (!(min_i <= max_i && min_j <= max_j)) {
                return 0;
            }
            int min_r = max_i + 1;
            int max_r = min_i - 1;
            int min_c = max_j + 1;
            int max_c = min_j - 1;
            for (int i = min_i; i <= max_i; ++i) {
                for (int j = min_j; j <= max_j; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
            return (max_r - min_r + 1) * (max_c - min_c + 1);
        };

        int result = numeric_limits<int>::max();
        for (int _ = 0; _ < 4; ++_) {
            for (int i = 0; i < size(grid); ++i) {
                const int a = minimumArea(0, i, 0, size(grid[0]) - 1);
                for (int j = 0; j < size(grid[0]); ++j) {
                    const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                    const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
                for (int j = i + 1; j < size(grid); ++j) {
                    const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                    const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                    result = min(result, a + b + c);
                }
            }
            grid = rotate(grid);
        }
        return result;
    }
};
