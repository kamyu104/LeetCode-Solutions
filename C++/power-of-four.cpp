// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num && !(num & 0b11)) {
            num >>= 2;
        }
        return (num == 1);
    }
};
