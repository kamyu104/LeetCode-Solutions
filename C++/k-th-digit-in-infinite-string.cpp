// Time:  O(logk)
// Space: O(1)

// math
class Solution {
public:
    int kthDigit(long long k) {
        const auto& digit = [](int64_t x, int i) {
            int r = 0;
            for (int _ = 0; _ < i; ++_) {
                r = x % 10;
                x /= 10;
            }
            return r;
        };
            
        --k;
        int64_t base = 1, l = 1;
        for (; 9 * base * l <= k; base *= 10, ++l) {
            k -= 9 * base * l;
        }
        const auto& q = k / l, &r = k % l;
        const auto& d = base + q;
        const auto& result = digit(d, l - r);
        return r != l - 1 || (d / 10) % 2 == 0 ? result : 9 - result;
    }
};

