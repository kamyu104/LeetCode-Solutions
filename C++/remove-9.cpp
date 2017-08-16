// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int newInteger(int n) {
        int result = 0, base = 1;
        while (n > 0) {
            result += (n % 9) * base;
            n /= 9;
            base *= 10;
        }
        return result;
    }
};
