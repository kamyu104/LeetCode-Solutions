// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int concatenatedBinary(int n) {
        static int MOD = 1e9 + 7;
        uint64_t result = 0, len = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++len;
            }
            result = ((result << len) % MOD + i) % MOD;
        }
        return result;
    }
};
