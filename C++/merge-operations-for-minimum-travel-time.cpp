// Time:  O((n - k) * k^3)
// Space: O(k^2)

// prefix sum, dp
class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        static const int INF = numeric_limits<int>::max();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + time[i];
        }
        unordered_map<int, unordered_map<int, int>> dp;
        dp[0][time[0]] = 0;
        for (int cnt = 2; cnt <= n - k; ++cnt) {
            unordered_map<int, unordered_map<int, int>> new_dp;
            for (int i = cnt - 1; i < (cnt - 1) + (k + 1); ++i) {
                for (int j = cnt - 2; j < i; ++j) {
                    for (const auto& [t, c] : dp[j]) {
                        const int nt = prefix[i + 1] - prefix[j + 1];
                        new_dp[i][nt] = min(new_dp[i].count(nt) ? new_dp[i][nt] : INF, (position[i] - position[j]) * t + c);
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = INF;
        for (const auto& [_, c] : dp[n - 1]) {
            result = min(result, c);
        }
        return result;
    }
};
