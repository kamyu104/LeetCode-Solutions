// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= n-1;
        }
        return n;
    }
};
