// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if ((i - k < 0 || nums[i - k] < nums[i]) &&
                (i + k >= size(nums) || nums[i + k] < nums[i])) {
                result += nums[i];
            }
        }
        return result;
    }
};
