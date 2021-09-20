// Time:  O(n + mlogm), m is the number of rides
// Space: O(n)

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides), end(rides));
        vector<int64_t> dp(n + 1);
        int j = 0;
        for(int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i - 1]);
            for (; j < size(rides) && rides[j][0] == i; ++j)
                dp[rides[j][1]] = max(dp[rides[j][1]], dp[i] + (rides[j][1] - rides[j][0] + rides[j][2]));
        }
        return dp.back();
    }
};
