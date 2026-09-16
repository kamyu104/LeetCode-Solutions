// Time:  O(n * sqrt(n))
// Space: O(n)

// dp
class Solution {
public:
    int minDays(int n) {
        static const auto& INF = numeric_limits<int>::max();

        const auto& count = [](int n) {
            return (n + 1) * n / 2;
        };

        vector<int> dp(n + 1, INF);
        dp[0] = -1;
        for (int d = 1; count(d) <= n; ++d) {
            for (int i = 0; i <= min<int>(count(d), size(dp) - 1 - count(d)); ++i) {
                dp[i + count(d)] = min(dp[i + count(d)], dp[i] + 1 + d);
            }
        }
        return dp.back();
    }
};
