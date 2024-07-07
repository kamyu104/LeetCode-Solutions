// Time:  O(nlogr)
// Space: O(logr)

// dp, lc3171
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int64_t result = 0;
        unordered_map<int, int> dp;
        for (const auto& x : nums) {
            unordered_map<int, int> new_dp;
            if ((x & k) == k) {
                ++new_dp[x];
                for (const auto& [y, c] : dp) {
                    new_dp[y & x] += c;
                }
                if (new_dp.count(k)) {
                    result += new_dp[k];
                }
            }
            dp = move(new_dp);
        }
        return result;
    }
};
