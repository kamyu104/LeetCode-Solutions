// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        nums.reserve(2 * size(nums));
        for (int i = size(nums) - 1; i >= 0; --i) {
            nums.emplace_back(nums[i]);
        }
        return nums;
    }
};
