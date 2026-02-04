// Time:  O(1)
// Space: O(1)

// greedy, game theory
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums.back());
    }
};
