// Time:  O(n * s), s is the sum of nums.
// Space: O(s)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
       const auto sum = accumulate(nums.cbegin(), nums.cend(), 0);
       if (sum % 2) {
           return false;
       }
       
       vector<bool> dp(sum / 2 + 1);
       dp[0]  = true;
       for (const auto& num : nums) {
           for (int i = 1; i < dp.size(); ++i) {
               if (num <= i) {
                   dp[i] = dp[i] || dp[i - num];
               }
           }
       }
       return dp.back();
    }
};
