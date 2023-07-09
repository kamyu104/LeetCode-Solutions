// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int result = -1, l = -1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (l != -1 && nums[i - 1] == nums[i + 1]) {
                ++l;
            } else {
                l = nums[i + 1] - nums[i] == 1 ? 2 : -1;
            }
            result = max(result, l);
        }
        return result;
    }
};
