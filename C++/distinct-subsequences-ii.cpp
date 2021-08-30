// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int distinctSubseqII(string S) {
        static const int MOD = 1e9 + 7;
        vector<int> dp(26);
        int result = 0;  // sum of dp
        for (const auto& c : S) {
            tie(result, dp[c - 'a']) = pair((result + 1 + (result - dp[c - 'a'] + MOD) % MOD) % MOD, result + 1);
        }
        return result;
    }
};
