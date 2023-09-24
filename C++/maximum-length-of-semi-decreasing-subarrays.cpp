// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (empty(stk) || nums[stk.back()] > nums[i]) {
                stk.emplace_back(i);
            }
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk) && nums[stk.back()] < nums[i]) {
                result = max(result, stk.back() - i + 1); stk.pop_back();
            }
        }
        return result;
    }
};
