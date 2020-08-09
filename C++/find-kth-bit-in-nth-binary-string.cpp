// Time:  O(n)
// Space: O(1)

class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0;  // init bit (S1) is 0
        for (int l = (1 << n) - 1; k > 1; l /= 2) {  // loop from Sn to S1, early return if k == 1
            if (k == l / 2 + 1) {
                flip ^= 1;  // hit mid, xor 1
                break;
            }
            if (k > l / 2) {
                k = l + 1 - k;
                flip ^= 1;  // right-hand side, invert once
            }
        }
        return '0' + flip;
    }
};
