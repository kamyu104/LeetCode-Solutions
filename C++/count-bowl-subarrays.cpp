// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int result = 0;
        vector<int> stk;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk) && nums[stk.back()] < nums[i]) {
                stk.pop_back();
                if (!empty(stk)) {
                    ++result;
                }
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
