// Time:  O(m * 4^m + n * 3^m)
// Space: O(3^m)

// worse complexity, but faster due to too small m
class Solution {
public:
    int colorTheGrid(int m, int n) {
        static const int MOD = 1e9 + 7;

        if (m > n) {
            swap(m, n);
        }
        vector<int> masks;
        backtracking(-1, m, &masks);  // Time:  O(2^m), Space: O(2^m)
        unordered_map<int, vector<int>> adj;
        for (const auto& mask1 : masks) {  // Time: O(m * 4^m), Space: O(3^m)
            for (const auto& mask2 : masks) {
                if (check(m, mask1, mask2)) {
                    adj[mask1].emplace_back(mask2);
                }
            }
        }
        assert(accumulate(cbegin(adj), cend(adj), 0,
                          [](const auto& total, const auto& kvp) {
                              return total + size(kvp.second);
                          }) <= 2 * pow(3, m));
        unordered_map<int, int> dp;
        for (const auto& mask : masks) {
            ++dp[mask];
        }
        for (int i = 0; i < n - 1; ++i) {  // Time: O(n*3^m), Space: O(2^m)
            assert(size(dp) <= 3 * 3 * pow(2, m - 2));
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
    void backtracking(int mask, int m, vector<int> *result) {  // Time: O(2^m), Space: O(2^m)
        if (!m) {
            result->emplace_back(mask);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (mask == -1 || mask % 3 != i) {
                backtracking(mask != -1 ? mask * 3 + i : i, m - 1, result);
            }
        }
    }
    
    bool check(int m, int mask1, int mask2) {  // Time: O(m)
        for (; m; mask1 /= 3, mask2 /= 3, --m) {
            if (mask1 % 3 == mask2 % 3) {
                return false;
            }
        }
        return true;
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
            assert(size(dp) <= 3 * 3 * pow(2, m - 2));
            int r = idx / m;
            int c = idx % m;
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
