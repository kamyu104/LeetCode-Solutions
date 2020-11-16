// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(cbegin(nums), cend(nums), 0) - x;
        int result = -1;
        int curr = 0, left = 0;
        for (int right = 0; right < size(nums); ++right) {
            curr += nums[right];
            while (left < size(nums) && curr > target) {
                curr -= nums[left++];
            }
            if (curr == target) {
                result = max(result, right - left + 1);
            }
        }
        return result != -1 ? size(nums) - result : -1;
    }
};
