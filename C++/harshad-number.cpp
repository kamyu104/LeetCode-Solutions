// Time:  O(logx)
// Space: O(1)

// math
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int result = 0;
        for (int y = x; y; y /= 10) {
            result += y % 10;
        }
        return x % result == 0 ? result : -1;
    }
};
