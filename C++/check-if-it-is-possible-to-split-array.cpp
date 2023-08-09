// Time:  O(n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if (size(nums) <= 2) {
            return true;
        }
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] + nums[i + 1] >= m) {
                return true;
            }
        }
        return false;
    }
};
