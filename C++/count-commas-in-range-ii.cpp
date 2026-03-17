// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    long long countCommas(long long n) {
        int cnt = 0;
        for (int64_t base = 1; base * 1000 <= n; base *= 1000) {
            ++cnt;
        }
        int64_t result = 0;
        for (int64_t i = 0, base = 1; i < cnt; ++i) {
            base *= 1000;
            result += n - base + 1;
        }
        return result;
    }
};
