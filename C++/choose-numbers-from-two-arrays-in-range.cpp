// Time:  O(n^2 * v), v is max(max(nums1), max(nums2))
// Space: O(n * v)

// dp
class Solution {
public:
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        static const int MOD = 1e9 + 7;
        
        int result = 0;
        unordered_map<int, int> dp;
        for (int i = 0; i < size(nums1); ++i) {
            unordered_map<int, int> new_dp;
            ++new_dp[nums1[i]];
            ++new_dp[-nums2[i]];
            for (const auto& [v, c] : dp) {
                new_dp[v + nums1[i]] = (new_dp[v + nums1[i]] + c) % MOD;
                new_dp[v - nums2[i]] = (new_dp[v - nums2[i]] + c) % MOD;
            }
            dp = move(new_dp);
            if (dp.count(0)) {
                result = (result + dp[0]) % MOD;
            }
        }
        return result;
    }
};
