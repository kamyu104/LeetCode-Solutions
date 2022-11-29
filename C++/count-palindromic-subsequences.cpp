// Time:  O(10^(l/2) * n * l), l = 5
// Space: O(l)

// dp
class Solution {
public:
    int countPalindromes(string s) {
        static const int MOD = 1e9 + 7;
        int result = 0;
        for (char i = '0'; i <= '9'; ++i) {
            for (char j = '0'; j <= '9'; ++j) {
                const string pattern = {i, j, '*', j, i};
                vector<int> dp(5 + 1);
                dp[0] = 1;
                for (int k = 0; k < size(s); ++k) {
                    for (int l = 4; l >= 0; --l) {
                        if (pattern[l] == '*' || pattern[l] == s[k]) {
                            dp[l + 1] = (dp[l + 1] + dp[l]) % MOD;
                        }
                    }
                }
                result = (result + dp[5]) % MOD;
            }
        }
        return result;
    }
};
