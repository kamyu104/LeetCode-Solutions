// Time:  O(n * t * c)
// Space: O(t)

// knapsack dp
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(target + 1);
        dp[0] = 1;
        for (const auto& t : types) {
            for (int i = target; i >= 1; --i) {
                for (int j = 1; j <= min(i / t[1], t[0]); ++j) {
                    dp[i] = (dp[i] + dp[i - j * t[1]]) % MOD;
                }
            }
        }
        return dp.back();
    }
};

// Time:  O(n * t * c)
// Space: O(t)
// knapsack dp
class Solution2 {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(target + 1);
        dp[0] = 1;
        for (const auto& t : types) {
            vector<int> new_dp(target + 1);
            for (int i = 0; i <= target; ++i) {
                for (int j = 0; j <= min((target - i) / t[1], t[0]); ++j) {
                    new_dp[i + j * t[1]] = (new_dp[i + j * t[1]] + dp[i]) % MOD;
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
