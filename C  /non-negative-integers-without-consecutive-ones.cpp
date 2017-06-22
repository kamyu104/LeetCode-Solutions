// Time:   O(1)
// Space: O(1)

class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(32);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int i = 30, sum = 0, prev_bit = 0;
        for (int i = 30; i >= 0; --i) {
            if ((num & (1 << i)) != 0) {
                sum += dp[i];
                if (prev_bit == 1) {
                    --sum;
                    break;
                }
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        return sum + 1;
    }
};
