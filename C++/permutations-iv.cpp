// Time:  O(n^2)
// Space: O(n)

// combinatorics
class Solution {
public:
    vector<int> permute(int n, long long k) {
        vector<int> result;
        vector<int64_t> cnt(n + 1, 1);
        for (int i = 1; i + 1 < size(cnt); ++i) {
            cnt[i + 1] = min(cnt[i] * ((i + 2) / 2), static_cast<int64_t>(k));
        }
        vector<bool> lookup(n);
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (!(!lookup[j] && ((i == 0 && n % 2 == 0) || ((j + 1) % 2 == (!empty(result) ? (result.back() % 2) ^ 1 : 1))))) {
                    continue;
                }
                if (k <= cnt[n - 1 - i]) {
                    break;
                }
                k -= cnt[n - 1 - i];
            }
            if (j == n) {
                return {};
            }
            lookup[j] = true;
            result.emplace_back(j + 1);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// combinatorics
class Solution2 {
public:
    vector<int> permute(int n, long long k) {
        typedef __int128 int128_t;

        vector<int> result;
        vector<int128_t> fact((((n - 1) + 1) / 2) + 1, 1);
        for (int i = 0; i + 1 < size(fact); ++i) {
            fact[i + 1] = min(fact[i] * (i + 1), static_cast<int128_t>(k));
        }
        vector<bool> lookup(n);
        for (int i = 0; i < n; ++i) {
            const auto cnt = fact[(n - 1 - i) / 2] * fact[((n - 1 - i) + 1) / 2];
            int j = 0;
            for (; j < n; ++j) {
                if (!(!lookup[j] && ((i == 0 && n % 2 == 0) || ((j + 1) % 2 == (!empty(result) ? (result.back() % 2) ^ 1 : 1))))) {
                    continue;
                }
                if (k <= cnt) {
                    break;
                }
                k -= cnt;
            }
            if (j == n) {
                return {};
            }
            lookup[j] = true;
            result.emplace_back(j + 1);
        }
        return result;
    }
};
