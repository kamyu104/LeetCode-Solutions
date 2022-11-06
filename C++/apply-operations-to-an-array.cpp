// Time:  O(n)
// Space: O(1)

// inplace, array
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int i = 0;
        for (const auto& x : nums) {
            if (x) {
                nums[i++] = x;
            }
        }
        for (; i < size(nums); ++i) {
            nums[i] = 0;
        }
        return nums;
    }
};
