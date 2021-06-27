// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool deleted = false;
        for (int i = 1; i < size(nums); ++i) {      
            if (nums[i] > nums[i - 1]) {
                continue;
            }
            if (deleted) {
                return false;
            }
            deleted = true;
            if (i >= 2 && nums[i - 2] > nums[i]) {  // delete nums[i] or nums[i-1]
                nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};
