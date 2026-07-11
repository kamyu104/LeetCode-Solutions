// Time:  O(n + m)
// Space: O(1)

// dp
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        vector<int> dp(2);
        for (const auto& x : t) {
            if (s[dp[1]] == x) {
                ++dp[1];
            }
            dp[1] = max(dp[1], dp[0] + 1);
            if (dp[1] == size(s)) {
                return true;
            }
            if (s[dp[0]] == x) {
                ++dp[0];
            }
        }
        return false;
    }
};
