// Time:  O(t + 26)
// Space: O(26)

// dp
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(26, 1);
        char c = ranges::max(s);
        for (int i = 26; i <= c - 'a' + t; ++i) {
            dp[i % 26] = (dp[(i - 26) % 26] + dp[((i - 26) + 1) % 26]) % MOD;
        }
        int result = 0;
        for (const auto& x : s) {
            result = (result + dp[((x - 'a') + t) % 26]) % MOD;
        }
        return result;
    }
};
