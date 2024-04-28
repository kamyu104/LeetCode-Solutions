// Time:  O(logn)
// Space: O(1)

// bit manipulation
class Solution {
public:
    long long minEnd(int n, int x) {
        --n;
        int64_t result = x;
        for (int64_t base_n = 1, base_x = 1; base_n <= n; base_x <<= 1) {
            if (x & base_x) {
                continue;
            }
            if (n & base_n) {
                result |= base_x;
            }
            base_n <<= 1;
        }
        return result;
    }
};
