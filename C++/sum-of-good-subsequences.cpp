// Time:  O(n)
// Space: O(n)

// freq table, dp
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        unordered_map<int, int64_t> dp, cnt;
        for (const auto& x : nums) {
            const int64_t c = cnt[x - 1] + cnt[x + 1] + 1;
            cnt[x] = (cnt[x] + c) % MOD;
            dp[x] = (dp[x] + dp[x - 1] + dp[x + 1] + x * c) % MOD;
        }
        return accumulate(cbegin(dp), cend(dp), 0, [](const auto& accu, const auto& x) {
            return (accu + x.second) % MOD;
        });
    }
};
