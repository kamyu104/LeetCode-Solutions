// Time:  O(n)
// Space: O(n)

// difference array
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> diff(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            ++diff[max(i - nums[i], 0)];
            --diff[i + 1];
        }
        for (int i = 0; i < size(nums); ++i) {
            diff[i + 1] += diff[i];
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += nums[i] * diff[i];
        }
        return result;
    }
};
