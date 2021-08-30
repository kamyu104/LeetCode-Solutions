// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int distinctSubseqII(string S) {
        static const int MOD = 1e9 + 7;
        vector<int> dp(26);
        int result = 0;  // sum of dp
        for (const auto& c : S) {
            const int delta = ((result + 1) - dp[c - 'a'] + MOD) % MOD;
            tie(result, dp[c - 'a']) = pair((result + delta) % MOD, (result + 1) % MOD);
        }
        return result;
    }
};
