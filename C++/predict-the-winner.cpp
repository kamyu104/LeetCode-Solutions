// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() % 2 == 0 || nums.size() == 1) {
            return true;
        }

        vector<int> dp(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i] = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        
        return dp.back() >= 0;
    }
};
