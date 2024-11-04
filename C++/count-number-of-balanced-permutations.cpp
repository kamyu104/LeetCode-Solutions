// Time:  O(9 * (9 * n / 2) * (n / 2)) = O(n^2)
// Space: O((9 * n / 2) * (n / 2)) = O(n^2)

// dp, combinatorics
class Solution {
public:
    int countBalancedPermutations(string num) {
        static const uint32_t MOD = 1e9 + 7;
        vector<int> fact = {1, 1};
        vector<int> inv = {1, 1};
        vector<int> inv_fact = {1, 1};
        const auto& lazy_init = [&](int n) {
            while (size(inv) <= n) {  // lazy initialization
                fact.emplace_back((static_cast<int64_t>(fact.back()) * size(inv)) % MOD);
                inv.emplace_back((static_cast<int64_t>(inv[MOD % size(inv)]) * (MOD - MOD / size(inv))) % MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.emplace_back((static_cast<int64_t>(inv_fact.back()) * inv.back()) % MOD);
            }
        };

        const auto& nCr = [&](int n, int k) {
            lazy_init(n);
            return (((static_cast<int64_t>(fact[n]) * inv_fact[n - k]) % MOD) * inv_fact[k]) % MOD;
        };
    
        const auto& factorial = [&](int n) {
            lazy_init(n);
            return fact[n];
        };

        const auto& inv_factorial = [&](int n) {
            lazy_init(n);
            return inv_fact[n];
        };

        int total = accumulate(cbegin(num), cend(num), 0, [](const auto& accu, const auto& x) {
            return accu + (x - '0');
        });
        if (total % 2) {
            return 0;
        }
        total /= 2;
        vector<int> cnt(26);
        for (const auto& x : num) {
            ++cnt[x - '0'];
        }
        const int even = size(num) / 2;
        vector<vector<int>> dp(total + 1, vector<int>(even + 1));
        dp[0][0] = 1;
        for (int i = 0; i < size(cnt); ++i) {
            if (!cnt[i]) {
                continue;
            }
            for (int j = total; j >= 0; --j) {
                for (int k = even; k >= 0; --k) {
                    if (!dp[j][k]) {
                        continue;
                    }
                    for (int c = 1; c <= cnt[i]; ++c) {
                        if (j + c * i <= total && k + c <= even) {
                            dp[j + c * i][k + c] = (dp[j + c * i][k + c] + ((static_cast<int64_t>(dp[j][k]) * nCr(cnt[i], c)) % MOD)) % MOD;
                        }
                    }
                }
            }
        }
        int result = (((static_cast<int64_t>(dp[total][even]) * factorial(even)) % MOD) * factorial(size(num) - even)) % MOD;
        for (const auto& x : cnt) {
            result = (static_cast<int64_t>(result) * inv_factorial(x)) % MOD;
        }
        return result;
    }
};
