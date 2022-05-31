// Time:  O(n)
// Space: O(n)

// mono stack, dp
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(size(nums));  // dp[i]: number of rounds for nums[i] to remove all the covered elements
         vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            while (!empty(stk) && nums[stk.back()] < nums[i]) {
                dp[i] = max(dp[i] + 1, dp[stk.back()]); stk.pop_back();
            }
            stk.emplace_back(i);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};

// Time:  O(n)
// Space: O(n)
// mono stack, dp
class Solution2 {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(size(nums));  // dp[i]: number of rounds for nums[i] to be removed
         vector<int> stk;
        for (int i = 0; i < size(nums); ++i) {
            int curr = 0;
            while (!empty(stk) && nums[stk.back()] <= nums[i]) {
                curr = max(curr, dp[stk.back()]); stk.pop_back();
            }
            if (!empty(stk)) {
                dp[i] = curr + 1;
            }
            stk.emplace_back(i);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};
