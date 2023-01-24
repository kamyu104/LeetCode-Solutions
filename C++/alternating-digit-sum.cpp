// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int alternateDigitSum(int n) {
        int result = 0, sign = 1;
        for (; n; n /= 10) {
            sign *= -1;
            result += sign * (n % 10);
        }
        return sign * result;
    }
};
