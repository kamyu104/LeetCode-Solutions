// Time:  O((m + n) * 3^m) = O(n * 3^m)
// Space: O(3^m)

// better complexity for small m, large n
class Solution {
public:
    int colorTheGrid(int m, int n) {
        static const int MOD = 1e9 + 7;

        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        vector<int> masks;
        backtracking(-1, -1, basis, &masks);  // Time: O(2^m), Space: O(2^m)
        unordered_map<int, vector<int>> adj;
        for (const auto& mask : masks) {  // O(3^m) leaves in depth O(m) => Time: O(m * 3^m), Space: O(3^m)
            backtracking(mask, -1, basis, &adj[mask]);
        }
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
        assert(accumulate(cbegin(adj), cend(adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) == 2 * pow(3, m));
        unordered_map<int, int> dp;
        for (const auto& mask : masks) {
            ++dp[mask];
        }
        for (int i = 0; i < n - 1; ++i) {  // Time: O(n * 3^m), Space: O(2^m)
            assert(size(dp) == 3 * pow(2, m - 1));
            unordered_map<int, int> new_dp;
            for (const auto [mask, v] : dp) {
                for (const auto& new_mask : adj[mask]) {
                    new_dp[new_mask] = (new_dp[new_mask] + v) % MOD;
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
};

// Time:  O(m * 3^m + 2^(3 * m) * logn)
// Space: O(2^(2 * m))

// better complexity for small m, super large n
class Solution2 {
public:
    int colorTheGrid(int m, int n) {
        if (m > n) {
            swap(m, n);
        }
        const int basis = pow(3, m - 1);
        unordered_set<int> masks;
        backtracking(-1, -1, basis, &masks);  // Time: O(2^m), Space: O(2^m)
        unordered_map<int, unordered_set<int>> adj;
        for (const auto& mask : masks) {  // O(3^m) leaves in depth O(m) => Time: O(m * 3^m), Space: O(3^m)
            backtracking(mask, -1, basis, &adj[mask]);
        }
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
        assert(accumulate(cbegin(adj), cend(adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) == 2 * pow(3, m));
        vector<vector<int>> matrix;
        for (const auto& mask1 : masks) {
            matrix.emplace_back();
            for (const auto& mask2 : masks)  {
                matrix.back().emplace_back(adj[mask1].count(mask2));
            }
        }
        const auto& result = matrixMult(vector<vector<int>>(1, vector<int>(size(masks), 1)),
                                        matrixExpo(matrix, n - 1));  // Time: O((2^m)^3 * logn), Space: O((2^m)^2)
        return accumulate(cbegin(result[0]), cend(result[0]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(2^m)
    }

private:
    void backtracking(int mask1, int mask2, int basis, unordered_set<int> *result) {  // Time: O(2^m), Space: O(2^m)
        if (!basis) {
            result->emplace(mask2);
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

    static const int MOD = 1e9 + 7;
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
        unordered_map<int, int> dp = {{(int(pow(3, m))) - 1, 1}};
        for (int idx = 0; idx < m * n; ++idx) {
            int r = idx / m;
            int c = idx % m;
            // sliding window with size m doesn't cross rows:
            //   [3, 2, ..., 2] => 3*2^(m-1) combinations
            assert(r != 0 || c != 0 || size(dp) == 1);
            assert(r != 0 || c == 0 || size(dp) == 3 * pow(2, c - 1));
            assert(r == 0 || c != 0 || size(dp) == 3 * pow(2, m - 1));
            // sliding window with size m crosses rows:
            //   [*, ..., *, *, 3, 2, ..., 2] => 3*3 * 2^(m-2) combinations
            //   [2, ..., 2, 3, *, *, ..., *]
            assert(r == 0 || c == 0 || size(dp) == 3 * 3 * pow(2, m - 2));
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
                    const auto new_mask = (x * basis) + (mask / 3);  // encoding mask
                    new_dp[new_mask] = (new_dp[new_mask] + v) % MOD;
                }
            }
            dp = move(new_dp);
        }
        return accumulate(cbegin(dp), cend(dp), 0,
                          [](const auto& total, const auto& kvp) {
                              return (total + kvp.second) % MOD;
                          });  // Time: O(2^m)
    }
};
