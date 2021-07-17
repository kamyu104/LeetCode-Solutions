// Time:  O(m * 2^m + 3^m + 2^(3 * m) * logn) = O(2^(3 * m) * logn)
// Space: O(2^(2 * m))

// better complexity for small m, super large n
class Solution {
public:
    int colorTheGrid(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        vector<int> masks;
        backtracking(-1, -1, basis, &masks);  // Time: O(2^m), Space: O(2^m)
        assert(size(masks) == 3 * pow(2, m - 1));
        unordered_map<int, int> lookup;
        for (const auto& mask : masks) {  // Time: O(m * 2^m)
            lookup[mask] = normalize(basis, mask);
        }
        unordered_map<int, int> normalized_mask_cnt;
        for (const auto& mask : masks) {
            normalized_mask_cnt[lookup[mask]] = (normalized_mask_cnt[lookup[mask]] + 1) % MOD;
        }
        assert(size(normalized_mask_cnt) == 3 * pow(2, m - 1) / 3 / (m >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
        unordered_map<int, vector<int>> adj;
        for (const auto& [mask, _] : normalized_mask_cnt) {  // O(3^m) leaves which are all in depth m => Time: O(3^m), Space: O(3^m)
            backtracking(mask, -1, basis, &adj[mask]);
        }
        unordered_map<int, unordered_map<int, int>> normalized_adj;
        for (const auto& [mask1, mask2s] : adj) {
            for (const auto& mask2 : mask2s) {
                normalized_adj[mask1][lookup[mask2]] = (normalized_adj[mask1][lookup[mask2]] + 1) % MOD;
            }
        }
        // divided by 3 * 2 is since the first two colors in upper row are normalized to speed up performance
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) <= 2 * pow(3, m) / 3 / 2);
        // since first two colors in lower row which has at most 3 choices could be also normalized, lower bound is upper bound divided by at most 3
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) >= 2 * pow(3, m) / 3 / 2 / 3);
        vector<vector<int>> matrix;
        vector<vector<int>> counts(1);
        for (const auto& [mask1, cnt] : normalized_mask_cnt) {
            matrix.emplace_back();
            for (const auto& [mask2, cnt] : normalized_mask_cnt)  {
                matrix.back().emplace_back(normalized_adj[mask1][mask2]);
            }
            counts[0].emplace_back(cnt);
        }
        const auto& result = matrixMult(counts, matrixExpo(matrix, n - 1));  // Time: O((2^m)^3 * logn), Space: O((2^m)^2)
        return accumulate(cbegin(result[0]), cend(result[0]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(2^m)
    }

private:
    void backtracking(int mask1, int mask2, int basis, vector<int> *result) {  // Time: O(2^m), Space: O(2^m)
        if (!basis) {
            result->emplace_back(mask2);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if ((mask1 == -1 || mask1 / basis % 3 != i) && (mask2 == -1 || mask2 / (basis * 3) % 3 != i)) {
                backtracking(mask1, mask2 != -1 ? mask2 + i * basis : i * basis, basis / 3, result);
            }
        }
    }

    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

    int normalize(int basis, int mask) {
        unordered_map<int, int> norm;
        int result = 0;
        for (; basis; basis /= 3) {
            int x = mask / basis % 3;
            if (!norm.count(x)) {
                norm[x] = size(norm);
            }
            result += norm[x] * basis;
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};

// Time:  O(n * 3^m)
// Space: O(3^m)
// better complexity for small m, large n
class Solution2 {
public:
    int colorTheGrid(int m, int n) {
        static const int MOD = 1e9 + 7;

        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        const auto& masks = find_masks(m, basis);  // alternative of backtracking, Time: O(2^m), Space: O(2^m)
        assert(size(masks) == 3 * pow(2, m - 1));
        unordered_map<int, int> lookup;
        for (const auto& mask : masks) {  // Time: O(m * 2^m)
            lookup[mask] = normalize(basis, mask);
        }
        unordered_map<int, int> dp;
        for (const auto& mask : masks) {  // normalize colors to speed up performance
            ++dp[lookup[mask]];
        }
        const auto& adj = find_adj(m, basis, dp);  // alternative of backtracking, Time: O(3^m), Space: O(3^m)
        // proof:
        //   'o' uses the same color with its bottom-left one, 
        //   'x' uses the remaining color different from its left one and bottom-left one,
        //   k is the cnt of 'o', 
        //    [3, 1(o), 1(x), 1(o), ..., 1(o), 1(x)] => nCr(m-1, k) * 3 * 2 * 2^k for k in xrange(m) = 3 * 2 * (2+1)^(m-1) = 2*3^m combinations
        //    [2,    2,    1,    2, ...,  2,      1]
        // another proof:
        //   given previous pair of colors, each pair of '?' has 3 choices of colors
        //     [3, ?, ?, ..., ?] => 3 * 2 * 3^(m-1) = 2*3^m combinations
        //         |  |       |
        //         3  3       3
        //         |  |       |
        //     [2, ?, ?, ..., ?]
        unordered_map<int, unordered_map<int, int>> normalized_adj;
        for (const auto& [mask1, mask2s] : adj) {
            for (const auto& mask2 : mask2s) {
                normalized_adj[lookup[mask1]][lookup[mask2]] = (normalized_adj[lookup[mask1]][lookup[mask2]] + 1) % MOD;
            }
        }
        // divided by 3 * 2 is since the first two colors in upper row are normalized to speed up performance
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) <= 2 * pow(3, m) / 3 / 2);
        // since first two colors in lower row which has at most 3 choices could be also normalized, lower bound is upper bound divided by at most 3
        assert(accumulate(cbegin(normalized_adj), cend(normalized_adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) >= 2 * pow(3, m) / 3 / 2 / 3);
        for (int i = 0; i < n - 1; ++i) {  // Time: O(n * 3^m), Space: O(2^m)
            assert(size(dp) == 3 * pow(2, m - 1) / 3 / (m >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
            unordered_map<int, int> new_dp;
            for (const auto [mask, v] : dp) {
                for (const auto& [new_mask, cnt] : normalized_adj[mask]) {
                    new_dp[lookup[new_mask]] = (new_dp[lookup[new_mask]] + (v * int64_t(cnt)) % MOD) % MOD;
                }
            }
            dp = move(new_dp);
        }
        return accumulate(cbegin(dp), cend(dp), 0,
                          [](const auto& total, const auto& kvp) {
                              return (total + kvp.second) % MOD;
                          });  // Time: O(2^m)
    }

private:
    vector<int> find_masks(int m, int basis) {  // Time: 3 + 3*2 + 3*2*2 + ... + 3*2^(m-1) = 3 * (2^m - 1) = O(2^m), Space: O(2^m)
        vector<int> masks = {0};
        for (int c = 0; c < m; ++c) {
            vector<int> new_masks;
            for (const auto& mask : masks) {
                vector<bool> used(3);
                if (c > 0) {
                    used[mask / basis] = true;  // get left grid
                }
                for (int x = 0; x < 3; ++x) {
                    if (used[x]) {
                        continue;
                    }
                    new_masks.emplace_back((x * basis) + (mask / 3));  // encoding mask
                }
            }
            masks = move(new_masks);
        }
        return masks;
    }

    unordered_map<int, vector<int>> find_adj(int m, int basis, const unordered_map<int, int>& dp) {
        // Time:  3*2^(m-1) * (1 + 2 + 2 * (3/2) + 2 * (3/2)^2 + ... + 2 * (3/2)^(m-2)) =
        //        3*2^(m-1) * (1+2*((3/2)^(m-1)-1)/((3/2)-1)) =
        //        3*2^(m-1) * (1+4*((3/2)^(m-1)-1)) =
        //        3*2^(m-1) * (4*(3/2)^(m-1)-3) =
        //        4*3^m-9*2^(m-1) =
        //        O(3^m),
        // Space: O(3^m)
        unordered_map<int, vector<int>> adj;
        for (const auto& [mask, _] : dp) {  // O(2^m)
            adj[mask].emplace_back(mask);
        }
        for (int c = 0; c < m; ++c) {
            assert(accumulate(cbegin(adj), cend(adj), 0,
                              [](const auto& total, const auto& kvp) {
                                  return total + size(kvp.second);
                              }) == (c ? pow(3, c) * pow(2, m - (c - 1)) : 3 * pow(2, m - 1)) / 3 / (m >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
            unordered_map<int, vector<int>> new_adj;
            for (const auto& [mask1, mask2s] : adj) {
                for (const auto& mask : mask2s) {
                    vector<bool> used(3);
                    used[mask % 3] = true;  // get up grid
                    if (c > 0) {
                        used[mask / basis] = true;  // get left grid
                    }
                    for (int x = 0; x < 3; ++x) {
                        if (used[x]) {
                            continue;
                        }
                        new_adj[mask1].emplace_back((x * basis) + (mask / 3));  // encoding mask
                    }
                }
            }
            adj = move(new_adj);
        }
        return adj;
    }
 
    int normalize(int basis, int mask) {
        unordered_map<int, int> norm;
        int result = 0;
        for (; basis; basis /= 3) {
            int x = mask / basis % 3;
            if (!norm.count(x)) {
                norm[x] = size(norm);
            }
            result += norm[x] * basis;
        }
        return result;
    }
};

// Time:  (m * n grids) * (O(3*3*2^(m-2)) possible states per grid) = O(n * m * 2^m)
// Space: O(3*3*2^(m-2)) = O(2^m)
// better complexity for large m, large n
class Solution3 {
public:
    int colorTheGrid(int m, int n) {
        static const int MOD = 1e9 + 7;

        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        int b = basis;
        unordered_map<int, unordered_map<int, int>> lookup;
        unordered_map<int, int> dp = {{0, 1}};
        for (int idx = 0; idx < m * n; ++idx) {
            int r = idx / m;
            int c = idx % m;
            // sliding window with size m doesn't cross rows:
            //   [3, 2, ..., 2] => 3*2^(m-1) combinations
            assert(r != 0 || c != 0 || size(dp) == 1);
            assert(r != 0 || c == 0 || size(dp) == 3 * pow(2, c - 1) / 3 / (c >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
            assert(r == 0 || c != 0 || size(dp) == 3 * pow(2, m - 1) / 3 / (m >= 2 ? 2 : 1));  // divided by 3 * 2 is since the first two colors are normalized to speed up performance
            // sliding window with size m crosses rows:
            //   [*, ..., *, *, 3, 2, ..., 2] => 3*3 * 2^(m-2) combinations
            //   [2, ..., 2, 3, *, *, ..., *]
            assert(r == 0 || c == 0 || size(dp) == (m == 1 ? 1 : m == 2 ? 2 : (3 * 3 * pow(2, m - 2) / 3 / 2)));  // divided by 3 * 2 for m >= 3 is since the first two colors of window are normalized to speed up performance
            unordered_map<int, int> new_dp;
            for (const auto [mask, v] : dp) {
                vector<bool> used(3);
                if (r > 0) {
                    used[mask % 3] = true;  // get up grid
                }
                if (c > 0) {
                    used[mask / basis] = true;  // get left grid
                }
                for (int x = 0; x < 3; ++x) {
                    if (used[x]) {
                        continue;
                    }
                    const auto new_mask = normalize(basis / b, ((x * basis) + (mask / 3)) / b, &lookup) * b;  // encoding mask
                    new_dp[new_mask] = (new_dp[new_mask] + v) % MOD;
                }
            }
            if (b > 1) {
                b /= 3;
            }
            dp = move(new_dp);
        }
        return accumulate(cbegin(dp), cend(dp), 0,
                          [](const auto& total, const auto& kvp) {
                              return (total + kvp.second) % MOD;
                          });  // Time: O(2^m)
    }

    int normalize(int basis, int mask, unordered_map<int, unordered_map<int, int>> *lookup) {  // compute and cache, at most O(3*2^(m-3)) time and space
        if (!(*lookup)[basis].count(mask)) {
            unordered_map<int, int> norm;
            int result = 0;
            for (int b = basis; b; b /= 3) {
                int x = mask / b % 3;
                if (!norm.count(x)) {
                    norm[x] = size(norm);
                }
                result += norm[x] * b;
            }
            (*lookup)[basis][mask] = result;
        }
        return (*lookup)[basis][mask];
    }
};
