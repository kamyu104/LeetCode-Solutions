// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = 0;
        for (; i < size(nums); ++i) {
            if ((start - i >= 0 && nums[start - i] == target) ||
                (start + i < size(nums) && nums[start + i] == target)) {
                break;
            }
        }
        return i;
    }
};
