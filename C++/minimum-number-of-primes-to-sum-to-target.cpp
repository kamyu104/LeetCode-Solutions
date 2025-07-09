// Time:  O(min(mlogm, n) + nlog(log(min(mlogm, n))) + m * n) = O(nlog(log(min(m, n))) + m * n)
// Space: O(n)

// number theory, knapsack dp
class Solution {
public:
    int minNumberOfPrimes(int n, int m) {
        static const int INF = numeric_limits<int>::max();

        vector<bool> is_prime(n + 1, true);
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 2, cnt = 0; i <= n; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
            for (int j = i; j <= n; ++j) {
                if (dp[j - i] != INF) {
                    dp[j] = min(dp[j], dp[j - i] + 1);
                }
            }
            if (++cnt == m) {
                break;
            }
        }
        return dp[n] != INF ? dp[n] : -1;
    }
};
