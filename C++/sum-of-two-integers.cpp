// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};
