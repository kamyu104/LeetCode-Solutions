// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while (X < Y) {
            if (Y % 2) {
                ++Y;
            } else {
                Y /= 2;
            }
            ++result;
        }
        return result + X - Y;
    }
};
