// Time:  O(logn)
// Space: O(1)

// bit manipulation, greedy
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        const int cnt1 = __builtin_popcount(num1), cnt2 = __builtin_popcount(num2);
        int result = num1;
        int cnt = abs(cnt1 - cnt2);
        const int expect = cnt1 >= cnt2 ? 1 : 0;
        for (int i = 0; cnt; ++i) {
            if (((num1 >> i) & 1) == expect) {
                --cnt;
                result ^= 1 << i;
            } 
        }
        return result;
    }
};
