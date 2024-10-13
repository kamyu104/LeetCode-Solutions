// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result(size(nums), -1);
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] & 1) {
                result[i] = nums[i] - (((nums[i] + 1) & (~nums[i])) >> 1);
            }
        }
        return result;
    }
};
