// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        while (num) {
            result += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return max(result - 1, 0);
    }
};
