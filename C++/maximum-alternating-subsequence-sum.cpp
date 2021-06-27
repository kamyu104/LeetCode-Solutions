// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = nums[0];
        for (int i = 0; i < size(nums) - 1; ++i) {
            result += max(nums[i + 1] - nums[i], 0);
        }
        return result;
    }
};
