// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        static const auto NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> dp(size(a) + 1, NEG_INF);   
        dp[0] = 0;
        for (const int64_t x : b) {
            for (int i = size(dp) - 1; i >= 1; --i) {
                if (dp[i - 1] != NEG_INF) {
                    dp[i] = max(dp[i], dp[i - 1] + x * a[i - 1]);
                }
            }
        }
        return dp.back();
    }
};
