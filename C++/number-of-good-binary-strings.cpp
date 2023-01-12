// Time:  O(n), n = maxLength
// Space: O(w), w = max(oneGroup, zeroGroup)+1

// dp
class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        const int w = max(oneGroup, zeroGroup) + 1;
        vector<int> dp(w);
        for (int i = 0; i <= maxLength; ++i) {
            dp[i % w] = i == 0 ? 1 : 0;
            if (i - oneGroup >= 0) {
                dp[i % w] = (dp[i % w] + dp[(i - oneGroup) % w]) % MOD;
            }
            if (i - zeroGroup >= 0 ) {
                dp[i % w] = (dp[i % w] + dp[(i - zeroGroup) % w]) % MOD;
            }
            if (i >= minLength) {
                result = (result + dp[i % w]) % MOD;
            }
        }
        return result;
    }
};

// Time:  O(n), n = maxLength
// Space: O(w), w = max(oneGroup, zeroGroup)+1
// dp
class Solution2 {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        const int w = max(oneGroup, zeroGroup) + 1;
        vector<int> dp(w);
        dp[0] = 1;
        for (int i = 0; i <= maxLength; ++i) {
            if (i >= minLength) {
                result = (result + dp[i % w]) % MOD;
            }
            if (i + oneGroup <= maxLength) {
                dp[(i + oneGroup) % w] = (dp[(i + oneGroup) % w] + dp[i % w]) % MOD;
            }
            if (i + zeroGroup <= maxLength) {
                dp[(i + zeroGroup) % w] = (dp[(i + zeroGroup) % w] + dp[i % w]) % MOD;
            }
            dp[i % w] = 0;
        }
        return result;
    }
};
