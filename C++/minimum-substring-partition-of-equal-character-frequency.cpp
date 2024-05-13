// Time:  O(n * (n + 26))
// Space: O(n + 26)

// dp, freq table
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(s) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(s); ++i) {
            vector<int> cnt(26);
            for (int j = i, d = 0, mx = 0; j >= 0; --j) {
                const int k = s[j] - 'a';
                if (++cnt[k] == 1) {
                    ++d;
                }
                mx = max(mx, cnt[k]);
                if (d * mx == i - j + 1) {
                    if (dp[j] != INF) {
                        dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                    }
                }
            }
        }
        return dp.back();
    }
};
