// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int countTexts(string pressedKeys) {
        static const int MOD = 1e9 + 7;
        vector<int> dp(5, 1);
        for (int i = 1; i <= size(pressedKeys); ++i) {
            dp[i % 5] = 0;
            const int start = (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') ? i - 4 : i - 3;
            for (int j = i - 1; j >= max(start, 0) && pressedKeys[j] == pressedKeys[i - 1]; --j) {
                dp[i % 5] = (dp[i % 5] + dp[j % 5]) % MOD;
            }            
        }
        return dp[size(pressedKeys) % 5];
    }
};
