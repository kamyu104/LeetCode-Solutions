// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (; n > 0 && n % 3 != 2; n /= 3);
        return n == 0;
    }
};
