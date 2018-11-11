// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int distinctSubseqII(string S) {
        static const int M = 1e9 + 7;
        vector<int> dp(26);
        int result = 0;  // sum of dp
        for (const auto& c : S) {
            tie(result, dp[c - 'a']) =
                make_pair(((2 * result) % M - dp[c - 'a'] + 1) % M,
                          (result + 1) % M);
        }
        return (result + M) % M;
    }
};
