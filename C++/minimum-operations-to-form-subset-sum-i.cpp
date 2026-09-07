// Time:  O(n * s * (logs + logr))
// Space: O(s)

// dp
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        static const auto& INF = numeric_limits<int>::max();

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            for (int i = size(dp) - 1; i >= 1; --i) {
                for (int nx = x, c = 0; i - nx >= 0; nx <<= 1, ++c) {
                    if (dp[i - nx] == INF) {
                        continue;
                    }
                    if (dp[i - nx] + c < dp[i]) {
                        dp[i] = dp[i - nx] + c;
                    }
                }
                for (int nx = x / 2, c = 1; nx; nx >>= 1, ++c) {
                    if (i - nx < 0 || dp[i - nx] == INF) {
                        continue;
                    }
                    if (dp[i - nx] + c < dp[i]) {
                        dp[i] = dp[i - nx] + c;
                    }
                }
            }
        }
        return dp[sum] != INF ? dp[sum] : -1;
    }
};


// Time:  O(n * s * (logs + logr))
// Space: O(s + logs + logr)
// dp
class Solution2 {
public:
    int minOperations(vector<int>& nums, int sum) {
        static const auto& INF = numeric_limits<int>::max();

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            vector<pair<int, int>> candidates;
            for (int nx = x, c = 0; sum - nx >= 0; nx <<= 1, ++c) {
                candidates.emplace_back(nx, c);
            }
            for (int nx = x / 2, c = 1; nx; nx >>= 1, ++c) {
                if (sum - nx >= 0) {
                    candidates.emplace_back(nx, c);
                }
            }
            vector<int> new_dp(dp);
            for (const auto& [nx, c] : candidates) {
                for (int i = nx; i < size(dp); ++i) {
                    if (dp[i - nx] == INF) {
                        continue;
                    }
                    if (dp[i - nx] + c < new_dp[i]) {
                        new_dp[i] = dp[i - nx] + c;
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[sum] != INF ? dp[sum] : -1;
    }
};
