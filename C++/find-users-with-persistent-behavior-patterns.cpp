// Time:  O(1)
// Space: O(1)

// game theory
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums.back());
    }
};
