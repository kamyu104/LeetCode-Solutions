// Time:  O(4^m + n * 3^m)
// Space: O(3^m)

// worse complexity, but faster due to too small m
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
        for (const auto& mask : masks) {  // Time: O(4^m), Space: O(3^m)
            backtracking(mask, -1, basis, &adj[mask]);
        }
        // 'o' uses the same color with its bottom-left one, 
        // 'x' uses the remaining color different from its left one and bottom-left one,
        // k is the cnt of 'o', 
        //   [2, 1(o), 1(x), 1(o), ..., 1(o), 1(x)] => nCr(m-1, k) * 3 * 2 * 2^k for k in xrange(m) = 3 * 2 * (2+1)^(m-1) = 2*3^m combinations
        //   [3,    2,    1,    2, ...,  2,      1]
        assert(accumulate(cbegin(adj), cend(adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) == 2 * pow(3, m));
        unordered_map<int, int> dp;
        for (const auto& mask : masks) {
            ++dp[mask];
        }
        for (int i = 0; i < n - 1; ++i) {  // Time: O(n*3^m), Space: O(2^m)
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

// Time:  (m * n grids) * (O(3*3*2^(m-2)) possible states per grid) = O(n * m * 2^m)
// Space: O(3*3*2^(m-2)) = O(2^m)
// better complexity, but slower due to too small m
class Solution2 {
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
