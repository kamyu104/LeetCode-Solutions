// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            if (result > numeric_limits<int>::max() / 10 ||
                (result == numeric_limits<int>::max() / 10 && x % 10 > numeric_limits<int>::max() % 10)) {
                return 0;
            }
            if (result < numeric_limits<int>::min() / 10 ||
                (result == numeric_limits<int>::min() / 10 && x % 10 < numeric_limits<int>::min() % 10)) {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
};
