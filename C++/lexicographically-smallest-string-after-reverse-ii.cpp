// Time:  O(nlogn)
// Space: O(n)

// rolling hash, binary search
class Solution {
public:
    string lexSmallest(string s) {
        static const int64_t MOD = 1e9 + 7;
        static const int64_t B = 29;
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
        for (int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = (prefix[i] * B + s[i]) % MOD;
        }
        vector<int64_t> suffix(n + 1);
        for (int i = size(suffix) - 2; i >= 0; --i) {
            suffix[i] = (suffix[i + 1] * B + s[i]) % MOD;
        }
        vector<int64_t> base(n + 1, 1);
        for (int i = 0; i + 1 < size(base); ++i) {
            base[i + 1] = (base[i] * B) % MOD;
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
    
        int best_k = 1, best_i = 0;
        auto is_less = [&](int k, int i) {
            const auto& idx = binary_search(0, n - 1, [&](int x) {
                return get_total_hash(k, i, x + 1) != get_total_hash(best_k, best_i, x + 1);
            });
            return idx != n && get_char(k, i, idx) < get_char(best_k, best_i, idx);
        };
        const auto& mn = ranges::min(s);
        for (int k = 1; k <= n; ++k) {
            if (s[k - 1] != mn) {
                continue;
            }
            if (is_less(k, 0)) {
                best_k = k;
                best_i = 0;
            }
        }
        for (int k = 1; k <= n; ++k) {
            if (!(s[size(s) - k] >= s.back())) {
                continue;
            }
            if (is_less(k, 1)) {
                best_k = k;
                best_i = 1;
            }
        }
        string result(s);
        if (!best_i) {
            reverse(begin(result), begin(result) + best_k);
        } else {
            reverse(begin(result) + (size(result) - best_k), end(result));
        }
        return result;
    }
};
