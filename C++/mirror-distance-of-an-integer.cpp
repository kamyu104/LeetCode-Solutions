// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int mirrorDistance(int n) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        return abs(n - reverse(n));
    }
};
