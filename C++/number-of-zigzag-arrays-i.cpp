// Time:  O(n * (r - l))
// Space: O(r - l)

// prefix sum, dp
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        static const int MOD = 1e9 + 7;

        r -= l;
        vector<int> dp(r + 1, 1);
        for (int _ = 0; _ < n - 1; ++_) {
            for (int i = 0, prefix = 0; i < size(dp); ++i) {
                tie(dp[i], prefix) = pair(prefix, (prefix + dp[i]) % MOD);
            }
            reverse(begin(dp), end(dp));
        }
        int result = 0;
        for (const auto& x : dp) {
            result = (result + x) % MOD;
        }
        return (result * 2) % MOD;
    }
};
