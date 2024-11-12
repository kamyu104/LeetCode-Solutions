// Time:  O(n^2)
// Space: O(n)

// dp
vector<int> cnt = {0, 0};
class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        static const int MOD = 1e9 + 7;

        while (size(s) - 1 >= size(cnt)) {  // cached
            cnt.emplace_back(cnt[__builtin_popcount(size(cnt))] + 1);
        }
        vector<int> dp(size(s));
        for (int i = 0, curr = 0; i < size(s); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
            }
            if (s[i] != '1') {
                continue;
            }
            dp[curr] = (dp[curr] + 1) % MOD;
            ++curr;
        }
        int result = 0;
        for (int i = 1; i < size(s); ++i) {
            if (cnt[i] < k) {
                result = (result + dp[i]) % MOD;
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp, combinatorics
// vector<int> cnt = {0, 0};
class Solution2 {
public:
    int countKReducibleNumbers(string s, int k) {
        static const int MOD = 1e9 + 7;
        vector<int> fact = {1, 1};
        vector<int> inv = {1, 1};
        vector<int> inv_fact = {1, 1};
        const auto& nCr = [&](int n, int k) {
            while (size(inv) <= n) {  // lazy initialization
                fact.emplace_back((static_cast<int64_t>(fact.back()) * size(inv)) % MOD);
                inv.emplace_back((static_cast<int64_t>(inv[MOD % size(inv)]) * (MOD - MOD / size(inv))) % MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact.emplace_back((static_cast<int64_t>(inv_fact.back()) * inv.back()) % MOD);
            }
            return (((static_cast<int64_t>(fact[n]) * inv_fact[n - k]) % MOD) * inv_fact[k]) % MOD;
        };

        while (size(s) - 1 >= size(cnt)) {  // cached
            cnt.emplace_back(cnt[__builtin_popcount(size(cnt))] + 1);
        }
        int result = 0;
        for (int i = 0, curr = 0; i < size(s); ++i) {
            if (s[i] != '1') {
                continue;
            }
            for (int c = 0; c <= size(s) - (i + 1); ++c) {
                if (cnt[curr + c] < k) {
                    result = (result + nCr(size(s) - (i + 1), c)) % MOD;
                }
            }
            ++curr;
        }
        return (((result - 1) % MOD) + MOD) % MOD;
    }
};
