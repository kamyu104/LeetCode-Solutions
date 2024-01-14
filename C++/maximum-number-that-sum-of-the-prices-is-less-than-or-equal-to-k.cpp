// Time:  O((logk)^2 / x)
// Space: O(1)

// bit manipulation, combinatorics
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        const auto& floor_log2 = [](long long x) {
            return 8 * sizeof(long long) - __builtin_clzll(x) - 1;
        };

        long long result = 0, prefix_cnt = 0;
        while (k >= prefix_cnt) {
            long long cnt = prefix_cnt;
            int i = 0;
            while ((cnt << x) + (1ll << (i + x - 1)) <= k) {
                cnt = (cnt << x) + (1ll << (i + x - 1));
                i += x;
            }
            const int c = min(cnt ? static_cast<int>(floor_log2(k / cnt)) : x - 1, x - 1);
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

// Time:  O(k * (logk) / x)
// Space: O(1)
// bit manipulation, binary search, combinatorics
class Solution2 {
public:
    long long findMaximumNumber(long long k, int x) {
        const auto& floor_log2 = [](long long x) {
            return 8 * sizeof(long long) - __builtin_clzll(x) - 1;
        };
    
        const auto& check = [&](long long v) {
            const auto& count = [&](long long v) {
                long long cnt = 0;
                for (int i = 0; (1ll << (i + x - 1)) <= v; i += x) {
                    const long long q = (v + 1) / (1ll << ((i + x - 1) + 1));
                    const long long r = (v + 1) % (1ll << ((i + x - 1) + 1));
                    cnt += q * 1 * (1ll << (i + x - 1)) + max(r - 1 * (1ll << (i + x - 1)), 0ll);
                }
                return cnt;
            };

            return count(v) <= k;
        };

        // long long left = 1, right = 1e15;
        long long left = 1, right = (1ll << (max(static_cast<int>(floor_log2(k)) + 1, x - 1) + 1)) - 1;  // right bound is verified by checking all possible (k, v) values, or just set right = solution.findMaximumNumber(10**15, 8) <= 10**15
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
