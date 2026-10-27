// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i + 1 < size(nums); ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                result += nums[i];
            } else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
                result -= nums[i];
            }
        }
        return result;
    }
};
