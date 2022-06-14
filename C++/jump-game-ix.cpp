// Time:  O(n)
// Space: O(1)

// dp, mono stack
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        vector<int> stk1, stk2;
        vector<int64_t> dp(size(nums), numeric_limits<int64_t>::max());
        dp[0] = 0;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk1) && nums[stk1.back()] <= nums[i]) {
                dp[i] = min(dp[i], dp[stk1.back()] + costs[i]);
                stk1.pop_back();
            }
            stk1.emplace_back(i);
            while (!empty(stk2) && nums[stk2.back()] > nums[i]) {
                dp[i] = min(dp[i], dp[stk2.back()] + costs[i]);
                stk2.pop_back();
            }
            stk2.emplace_back(i);
        }
        return dp.back();
    }
};
