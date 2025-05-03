// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        vector<long long> dp(k);
        for (const auto& x : nums) {
            vector<long long> new_dp(k);
            ++new_dp[x % k];
            for (int64_t i = 0; i < size(dp); ++i) {
                new_dp[i * x % k] += dp[i];
            }
            for (int i = 0; i < size(new_dp); ++i) {
                result[i] += new_dp[i];
            }
            dp = move(new_dp);
        }
        return result;
    }
};
