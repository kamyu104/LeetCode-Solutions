// Time:  O(n)
// Space: O(n)

// combinatorics
class Solution {
public:
    int countAnagrams(string s) {
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

        const auto& factorial = [&](int n) {
            lazy_init(n);
            return fact[n];
        };

        const auto& inv_factorial = [&](int n) {
            lazy_init(n);
            return inv_fact[n];
        };

        const auto& count = [&](int j, int i) {
            vector<int> cnt(26);
            for (int k = j; k <= i; ++k) {
                ++cnt[s[k] - 'a'];
            }
            int64_t result = 1;
            int total = 0;
            for (const auto& c : cnt) {
                total += c;
                result = (result * inv_factorial(c)) % MOD;
            }
            return (result * factorial(total)) % MOD;
        };

        int result = 1;
        for (int i = 0, j = 0; i < size(s); ++i) {
            if (i + 1 != size(s) && s[i + 1] != ' ') {
                continue;
            }
            result = (result * count(j, i)) % MOD;
            j = i + 2;
        }
        return result;
    }
};
