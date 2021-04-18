// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result(size(nums));
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < size(nums); ++i) {
            result[size(nums) - 1 - i] = mask ^= nums[i];
        }
        return result;
    }
};
