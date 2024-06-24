// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i + 2 < size(nums); ++i) {
            if (nums[i]) {
                continue;
            }
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ++result;
        }
        return nums[size(nums) - 2] == nums[size(nums) - 1] && nums[size(nums) - 1] == 1 ? result : -1;
    }
};
