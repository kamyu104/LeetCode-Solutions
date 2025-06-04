// Time:  O(n^3)
// Space: O(n^2)

// dp
class Solution {
public:
    string lexicographicallySmallestString(string s) {
        vector<vector<bool>> dp(size(s), vector<bool>(size(s)));
        for (int l = 2; l <= size(s); l += 2) {
            for (int i = 0; i + (l - 1) < size(s); ++i) {
                const int j = i + (l - 1);
                if ((abs(s[i] - s[j]) == 1 || abs(s[i] - s[j]) == 25)) {
                    if (j == i + 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        continue;
                    }
                }
                for (int k = i + 1; k < j; k += 2) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        vector<string> dp2(size(s) + 1);
        for (int i = size(s) - 1; i >= 0; --i) {
            dp2[i] = s[i] + dp2[i + 1];
            for (int j = i + 1; j < size(s); j += 2) {
                if (dp[i][j]) {
                    dp2[i] = min(dp2[i], dp2[j + 1]);  
                }
            }
        }
        return dp2[0];
    }
};
