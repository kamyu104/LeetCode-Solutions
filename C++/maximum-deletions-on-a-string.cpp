// Time:  O(n^2)
// Space: O(n^2)

// dp
class Solution {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int>> dp(size(s) + 1, vector<int>(size(s) + 1));  // dp[i][j]: max prefix length of s[i:] and s[j:]
        vector<int> dp2(size(s), 1);  // dp2[i]: max operations of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                if (s[j] == s[i]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                if (dp[i][j] >= j - i) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        return dp2[0];
    }
};
