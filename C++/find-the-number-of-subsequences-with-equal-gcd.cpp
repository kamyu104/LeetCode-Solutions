// Time:  O(n * r^2 * logr)
// Space: O(r^2)

// dp, number theory
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        const int mx = ranges::max(nums);
        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));
        dp[0][0] = 1;
        for (const auto& x : nums) {
            vector<vector<int>> new_dp(dp);
            for (int g1 = mx; g1 >= 0; --g1) {
                for (int g2 = mx; g2 >= 0; --g2) {
                    const auto& ng1 = gcd(g1, x);
                    const auto& ng2 = gcd(g2, x);
                    new_dp[ng1][g2] = (new_dp[ng1][g2] + dp[g1][g2]) % MOD;
                    new_dp[g1][ng2] = (new_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (int g = 1; g <= mx; ++g) {
            result = (result + dp[g][g]) % MOD;
        }
        return result;
    }
};

// Time:  O(n * r^2 * logr)
// Space: O(r^2)
// dp, number theory
class Solution2 {
public:
    int subsequencePairCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, unordered_map<int, int>> dp;
        dp[0][0] = 1;
        for (const auto& x : nums) {
            unordered_map<int, unordered_map<int, int>> new_dp;
            for (const auto& [g1, dp_g1] : dp) {
                for (const auto& [g2, cnt] : dp_g1) {
                    const auto& ng1 = gcd(g1, x);
                    const auto& ng2 = gcd(g2, x);
                    new_dp[g1][g2] = (new_dp[g1][g2] + cnt) % MOD;
                    new_dp[ng1][g2] = (new_dp[ng1][g2] + cnt) % MOD;
                    new_dp[g1][ng2] = (new_dp[g1][ng2] + cnt) % MOD;
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (const auto& [g1, dp_g1] : dp) {
            if (g1 == 0) {
                continue;
            }
            for (const auto& [g2, cnt] : dp_g1) {
                if (g2 != g1) {
                    continue;
                }
                result = (result + cnt) % MOD;
            }
        }
        return result;
    }
};
