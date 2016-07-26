// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int number = 0;
        while (n > 0) {
            number += n / 5;
            n /= 5;
        }
        return number;
    }
};
