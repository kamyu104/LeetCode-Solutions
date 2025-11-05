// Time:  O(nlogn)
// Space: O(n)

// rolling hash, binary search
class Solution {
public:
    string lexSmallest(string s) {
        static const int64_t MOD = 1e9 + 7;
        static const int64_t D = 27;
        const int n = size(s);

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

        vector<int64_t> prefix(n + 1);
        for (int i = 0; i + 1 < n; ++i) {
            prefix[i + 1] = (prefix[i] * D + s[i]) % MOD;
        }
        vector<int64_t> suffix(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = (suffix[i + 1] * D + s[i]) % MOD;
        }
        vector<int64_t> base(n + 1, 1);
        for (int i = 0; i + 1 < n; ++i) {
            base[i + 1] = (base[i] * D) % MOD;
        }

        const auto& get_prefix_hash = [&](int l, int r) {
            if (l > r) {
                return static_cast<int64_t>(0);
            }
            return (prefix[r + 1] - prefix[l] * base[r - l + 1] % MOD + MOD) % MOD;
        };

        const auto& get_suffix_hash = [&](int l, int r) {
            if (l > r) {
                return static_cast<int64_t>(0);
            }
            return (suffix[l] - suffix[r + 1] * base[r - l + 1] % MOD + MOD) % MOD;
        };

        const auto& get_total_hash = [&](int k, int t, int l) {
            if (!t) {
                return l <= k
                    ? get_suffix_hash(k - l, k - 1)
                    : ((get_suffix_hash(0, k - 1) * base[l - k]) % MOD + get_prefix_hash(k, l - 1)) % MOD;
            }
            const auto& nk = n - k;
            return l <= nk
                ? get_prefix_hash(0, l - 1)
                : ((get_prefix_hash(0, nk - 1) * base[l - nk]) % MOD + get_suffix_hash(n - (l - nk), n - 1)) % MOD;
        };

        const auto& get_char = [&](int k, int t, int idx) {
            if (!t) {
                return idx < k
                    ? s[(k - 1) - idx]
                    : s[idx];
            }
            return idx < n - k
                ? s[idx]
                : s[(n - 1) - (idx - (n - k))];
        };
    
        vector<int> best = {1, 0};
        auto is_less = [&](const vector<int>& t) {
            const auto& i = binary_search(0, n - 1, [&](int x) {
                return get_total_hash(t[0], t[1], x + 1) != get_total_hash(best[0], best[1], x + 1);
            });
            return i != n && get_char(t[0], t[1], i) < get_char(best[0], best[1], i);
        };

        for (int t = 0; t < 2; ++t) {
            for (int k = 1; k <= n; ++k) {
                if (is_less({k, t})) {
                    best = {k, t};
                }
            }
        }
        string result(s);
        if (!best[1]) {
            reverse(begin(result), begin(result) + best[0]);
        } else {
            reverse(begin(result) + (size(result) - best[0]), end(result));
        }
        return result;
    }
};
