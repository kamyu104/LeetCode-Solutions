// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        while (num) {
            if (num & 1) {
                --num;
            } else {
                num >>= 1;
            }
            ++result;
        }
        return result;
    }
};
