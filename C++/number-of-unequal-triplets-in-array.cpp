// Time:  O(n * k) = O(3 * n)
// Space: O(n + k) = O(n)

// freq table, dp
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        static const int K = 3;

        unordered_map<int, int> cnt;
        vector<int> dp(K);  // dp[i]: number of unequal (i+1)-plets
        for (const auto& x : nums) {
            ++cnt[x];
            int other_cnt = 1;
            for (int i = 0; i < K; ++i) {
                dp[i] += other_cnt;
                other_cnt = dp[i] - cnt[x] * other_cnt;
            }
        }
        return dp[K - 1];
    }
};
