// Time:  O((n + m) * log(min(n, m)))
// Space: O(min(n, m))

// binary search, rolling hash
class Solution {
public:
    int minOperations(string initial, string target) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& rolling_hash = [](const auto& s, int l, auto& lookup, bool check) {
            static const int MOD = 1e9 + 7, P = 113;
    
            int64_t h = 0, pw = 1;
            for (int i = 0; i < size(s); ++i) {
                h = (h * P + (s[i] - 'a')) % MOD;
                if (i < l - 1) {
                    pw = (pw * P) % MOD;
                    continue;
                }
                if (!check) {
                    lookup.emplace(h);
                } else if (lookup.count(h)) {
                    return true;
                }
                h = ((h - (s[i - (l - 1)] - 'a') * pw % MOD) + MOD) % MOD;
            }
            return false;
        };

        const auto& check = [&](int l) {
            unordered_set<int> lookup;
            rolling_hash(target, l, lookup, false);
            return rolling_hash(initial, l, lookup, true);
        };

        if (size(initial) < size(target)) {
            swap(initial, target);
        }
        return size(initial) + size(target) - 2 * binary_search_right(1, min(size(initial), size(target)), check);
    }
};

// Time:  O(n * m)
// Space: O(1)
// dp
class Solution2 {
public:
    int minOperations(string initial, string target) {
        int result = 0;
        for (int k = 0; k < 2; ++k) {
            for (int i = k; i < size(initial); ++i) {
                int curr = 0;
                for (int j = 0; j < min(size(initial) - i, size(target)); ++j) {
                    curr = initial[i + j] == target[j] ? curr + 1 : 0;
                    result = max(result, curr);
                }
            }
            swap(initial, target);
        }
        return size(initial) + size(target) - 2 * result;
    }
};

// Time:  O(n * m)
// Space: O(min(n, m))
// dp
class Solution3 {
public:
    int minOperations(string initial, string target) {
        if (size(initial) < size(target)) {
            swap(initial, target);
        }
        int result = 0;
        vector<int> dp(size(target) + 1);
        for (int i = 0; i < size(initial); ++i) {
            for (int j = size(target) - 1; j >= 0; --j) {
                dp[j + 1] = initial[i] == target[j] ? dp[j] + 1 : 0;
            }
            result = max(result, ranges::max(dp));
        }
        return size(initial) + size(target) - 2 * result;
    }
};
