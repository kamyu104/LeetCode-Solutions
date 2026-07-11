// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int result = 0, prefix = 0;
        for (int i = 0; i + k < size(nums); ++i) {
            prefix = max(prefix, nums[i]);
            result = max(result, prefix + nums[i + k]);
        }
        return result;
    }
};
