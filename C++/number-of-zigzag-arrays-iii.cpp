// Time:  O(n^3)
// Space: O(n)

// dp, prefix sum, lagrange interpolation
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        static const uint32_t MOD = 1e9 + 7;

        vector<int64_t> inv = {1, 1};
        vector<int64_t> inv_fact = {1, 1};
        const auto& inv_factorial = [&](int n) {
            while (size(inv) <= n) {  // lazy initialization
                inv.emplace_back((static_cast<int64_t>(inv[MOD % size(inv)]) * (MOD - MOD / size(inv))) % MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.emplace_back((static_cast<int64_t>(inv_fact.back()) * inv.back()) % MOD);
            }
            return inv_fact[n];
        };

        const auto& f = [&](int x) {
            vector<int64_t> dp(x);
            iota(begin(dp), end(dp), 0);
            for (int _ = 0; _ < n - 2; ++_) {
                vector<int64_t> new_dp(x);
                for (int i = 0; i + 1 < x; ++i) {
                    new_dp[i + 1] = (new_dp[i] + dp[x - 1 - i]) % MOD;
                }
                dp = move(new_dp);
            }
            int64_t total = 0;
            for (int i = 0; i < x; ++i) {
                total = (total + dp[i]) % MOD;
            }
            return (total * 2) % MOD;
        };

        const auto& m = r - l + 1;
        if (m <= n + 1) {
            return f(m);
        }
        vector<int64_t> y(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            y[i] = f(i + 1);
        }
        vector<int64_t> prefix((n + 1) + 1);
        prefix[0] = 1;
        for (int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = prefix[i] * (((m - 1 - i) % MOD + MOD) % MOD) % MOD;
        }
        vector<int64_t> suffix((n + 1) + 1);
        suffix.back() = 1;
        for (int i = size(suffix) - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * (((m - 1 - i) % MOD + MOD) % MOD) % MOD;
        }
        int64_t result = 0;
        for (int i = 0; i < n + 1; i++) {
            result = (result + (((((y[i] * ((prefix[i] * suffix[i + 1]) % MOD)) % MOD) * ((inv_factorial(i) * inv_factorial(n - i)) % MOD)) % MOD) * ((n - i) % 2 ? (MOD - 1) : 1)) % MOD) % MOD;
        }
        return result;
    }
};
