// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result(size(nums) - k + 1, -1);
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (nums[right] - nums[left] != right - left) {
                left = right;
            }
            if (right - left + 1 == k) {
                result[left++] = nums[right];
            }
        }
        return result;
    }
};
