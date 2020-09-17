// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int countDigitOne(int n) {
        static const int DIGIT = 1;

        int is_zero = (DIGIT == 0) ? 1 : 0;
        int result = is_zero;
        for (int64_t base = 1; n >= base; base *= 10) {
            result += (n / (10 * base) - is_zero) * base +
                      min(base, max(n % (10 * base) - DIGIT * base + 1, 0l));
        }
        return result;
    }
};
