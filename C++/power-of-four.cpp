// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 &&
               ((num & 0b01010101010101010101010101010101) == num);
    }
};

// Time:  O(1)
// Space: O(1)
class Solution2 {
public:
    bool isPowerOfFour(int num) {
        while (num && !(num & 0b11)) {
            num >>= 2;
        }
        return (num == 1);
    }
};
