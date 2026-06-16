// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    bool checkGoodInteger(int n) {
        int result = 0;
        for (; n; n /= 10) {
            const auto& r = n % 10;
            result += r * r - r;
        }
        return result >= 50;
    }
};
