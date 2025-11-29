// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    long long sumAndMultiply(int n) {
        const auto& reverse = [](int64_t n) {
            int64_t result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        int64_t total = 0, x = 0;
        for (; n; n /= 10) {
            total += n % 10;
            if (n % 10) {
                x = x * 10 + n % 10;
            }
        }
        return reverse(x) * total;
    }
};
