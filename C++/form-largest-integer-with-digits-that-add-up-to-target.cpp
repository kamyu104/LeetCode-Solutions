// Time:  O(t)
// Space: O(t)

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;
        for (int t = 1; t <= target; ++t) {
            for (int i = 0; i < 9; ++i) {
                if (t < cost[i] || dp[t - cost[i]] < 0) {
                    continue;
                }
                dp[t] = max(dp[t], dp[t - cost[i]] + 1);
            }
        }
        if (dp[target] < 0) {
            return "0";
        }
        string result;
        for (int i = 8; i >= 0; --i) {
            while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
                result.push_back('1' + i);
                target -= cost[i];
            }
        }
        return result;
    }
};
