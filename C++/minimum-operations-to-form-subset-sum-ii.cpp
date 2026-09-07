// Time:  O(n * logr * logs * s)
// Space: O(s + logr * logs)

// knapsack dp
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            vector<int> lookup(sum + 1, INF);
            for (int nx1 = x, c1 = 0; nx1; nx1 >>= 1, ++c1) {
                for (int nx2 = nx1, c2 = c1; nx2 <= sum; nx2 <<= 1, ++c2) {
                    if (c2 < lookup[nx2]) {
                        lookup[nx2] = c2;
                    }
                }
            }
            vector<int> new_dp(dp);
            for (int nx = 1; nx < size(lookup); ++nx) {
                if (lookup[nx] == INF) {
                    continue;
                }
                const auto& c = lookup[nx];
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

// Time:  O(n * logr * logs * s)
// Space: O(s + logr * logs)
// knapsack dp
class Solution2 {
public:
    int minOperations(vector<int>& nums, int sum) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            vector<int> lookup(sum + 1, INF);
            for (int nx1 = x, c1 = 0; nx1; nx1 >>= 1, ++c1) {
                for (int nx2 = nx1, c2 = c1; nx2 <= sum; nx2 <<= 1, ++c2) {
                    if (c2 < lookup[nx2]) {
                        lookup[nx2] = c2;
                    }
                }
            }
            vector<pair<int, int>> candidates;
            for (int nx = 1; nx < size(lookup); ++nx) {
                if (lookup[nx] != INF) {
                    candidates.emplace_back(nx, lookup[nx]);
                }
            }
            for (int i = sum; i >= 1; --i) {
                for (const auto& [nx, c] : candidates) {
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

// Time:  O(n * logr * logs * s)
// Space: O(s)
// knapsack dp
class Solution3 {
public:
    int minOperations(vector<int>& nums, int sum) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (const auto& x : nums) {
            vector<int> new_dp(dp);
            for (int nx1 = x, c1 = 0; nx1; nx1 >>= 1, ++c1) {
                for (int nx2 = nx1, c2 = c1; nx2 <= sum; nx2 <<= 1, ++c2) {
                    for (int i = nx2; i < size(dp); ++i) {
                        if (dp[i - nx2] == INF) {
                            continue;
                        }
                        if (dp[i - nx2] + c2 < new_dp[i]) {
                            new_dp[i] = dp[i - nx2] + c2;
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[sum] != INF ? dp[sum] : -1;
    }
};
