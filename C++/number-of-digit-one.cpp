// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int countDigitOne(int n) {
        static const int digit = 1;
        int result = 0;
        for (int64_t base = 1; n >= base; base *= 10) {
            result += n / (10 * base) * base +
                      min(base, max(n % (10 * base) - digit * base + 1, 0l));
        }
        return result;
    }
};
