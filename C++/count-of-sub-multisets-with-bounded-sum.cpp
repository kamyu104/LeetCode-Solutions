// Time:  O(n + d * r), d = len(set(nums))
// Space: O(d + r)

// freq table, knapsack dp, sliding window, combinatorics
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        vector<int> dp(r + 1);
        dp[0] = 1;
        for (const auto& [x, c] : cnt) {
            for (int i = r; i >= max(r - x + 1, 1); --i) {
                int curr = 0;
                for (int j = 0; j < c; ++j) {
                    if (i - x * j < 0) {
                        break;
                    }
                    curr = (curr + dp[i - x * j]) % MOD;
                }
                for (int j = i; j >= 1 ; j -= x) {
                    if (j - x * c >= 0) {
                        curr = (curr + dp[j - x * c]) % MOD;
                    }
                    curr = ((curr - dp[j]) % MOD + MOD) % MOD;
                    dp[j] = (dp[j] + curr) % MOD;
                }
            }
        }
        int64_t result = accumulate(cbegin(dp) + l, cbegin(dp) + (r + 1), 0, [&](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        });
        return (result * (cnt[0] + 1)) % MOD;
    }
};
