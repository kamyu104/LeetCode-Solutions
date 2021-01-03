// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int left = 0, right = 1, l = 0;
        while (right + k - 1 < size(nums) && right + l < size(nums)) {
            if (nums[left + l] == nums[right + l]) {
                ++l;
                continue;
            }
            if (nums[left + l] > nums[right + l]) {
                right += l + 1;
            } else {
                left = max(right, min(left + l + 1, int(size(nums)) - k));
                right = left + 1;
            }
            l = 0;
        }
        return {cbegin(nums) + left, cbegin(nums) + left + k};
    }
};
