// Time:  O(max(logk, x) * log((logk) / x))
// Space: O((logk) / x)

// bit manipulation, binary search, combinatorics
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        const auto& binary_search_right = [](long long left, long long right, const auto& check) {
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

        long long result = 0, prefix_cnt = 0;
        vector<long long> lookup = {0};
        for (int i = 0; (lookup.back() << x) + (1ll << (i + x - 1)) <= k; i += x) {
            lookup.emplace_back((lookup.back() << x) + (1ll << (i + x - 1)));
        }
        const auto& count = [&](int l) {
            return (prefix_cnt << (x * l)) + lookup[l];
        };

        while (k >= prefix_cnt) {
            const auto& l = binary_search_right(1, size(lookup) - 1, [&](int l) {
                return count(l) <= k;
            });
            long long cnt = count(l);
            int i = x * l;
            const int c = min(cnt ? static_cast<int>(__lg(k / cnt)) : x - 1, x - 1);
            cnt <<= c;
            i += c;
            k -= cnt;
            result += 1ll << i;
            if ((i + 1) % x == 0) {
                ++prefix_cnt;
            }
        }
        return result - 1;
    }
};

// Time:  O(max(logk, x) * (max(logk, x) / x))
// Space: O(1)
// bit manipulation, combinatorics
class Solution2 {
public:
    long long findMaximumNumber(long long k, int x) {
        long long result = 0, prefix_cnt = 0;
        while (k >= prefix_cnt) {
            long long cnt = prefix_cnt;
            int i = 0;
            for (; (cnt << x) + (1ll << (i + x - 1)) <= k; i += x) {
                cnt = (cnt << x) + (1ll << (i + x - 1));
            }
            const int c = min(cnt ? static_cast<int>(__lg(k / cnt)) : x - 1, x - 1);
            cnt <<= c;
            i += c;
            k -= cnt;
            result += 1ll << i;
            if ((i + 1) % x == 0) {
                ++prefix_cnt;
            }
        }
        return result - 1;
    }
};

// Time:  O(max(logk, x)^2)
// Space: O(1)
// bit manipulation, combinatorics
class Solution3 {
public:
    long long findMaximumNumber(long long k, int x) {
        long long result = 0, prefix_cnt = 0;
        while (k >= prefix_cnt) {
            long long cnt = prefix_cnt;
            int i = 0;
            for (; (cnt << 1) + ((i + 1) % x == 0 ? 1ll << i : 0) <= k; ++i) {
                cnt = (cnt << 1) + ((i + 1) % x == 0 ? 1ll << i : 0);
            }
            k -= cnt;
            result += 1ll << i;
            if ((i + 1) % x == 0) {
                ++prefix_cnt;
            }
        }
        return result - 1;
    }
};

// Time:  O(max(logk, x) * (max(logk, x) / x))
// Space: O(1)
// bit manipulation, binary search, combinatorics
class Solution4 {
public:
    long long findMaximumNumber(long long k, int x) {
        const auto& binary_search_right = [](long long left, long long right, const auto& check) {
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

        const auto& count = [&](long long v) {
            long long cnt = 0;
            for (int i = 0; (1ll << (i + x - 1)) <= v; i += x) {
                const long long q = (v + 1) / (1ll << ((i + x - 1) + 1));
                const long long r = (v + 1) % (1ll << ((i + x - 1) + 1));
                cnt += q * 1 * (1ll << (i + x - 1)) + max(r - 1 * (1ll << (i + x - 1)), 0ll);
            }
            return cnt;
        };
    
        return binary_search_right(1, max(k << 2, 1ll << x), [&](long long v) {
            return count(v) <= k;
        });  // right bound is verified by checking all possible (k, v) values, or just set right = solution.findMaximumNumber(10**15, 8) <= 10**15
    }
};
