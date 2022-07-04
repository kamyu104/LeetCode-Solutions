// Time:  O(n)
// Space: O(f)

// dp
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        static const int MOD = 1e9 + 7;
        vector<int> dp(forget);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i % forget] = (((i - 1 ? dp[(i - 1) % forget] : 0) - dp[i % forget] + dp[((i - delay) % forget + forget) % forget]) % MOD + MOD) % MOD;
            
        }
        return accumulate(cbegin(dp), cend(dp), 0,
                          [&](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });
    }
};
