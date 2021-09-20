// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> right(size(nums), nums.back());
        for (int i = size(nums) - 2; i >= 2; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int result = 0, left = nums.front();
        for (int i = 1; i <= size(nums) - 2; ++i) {
            if (left < nums[i] && nums[i] < right[i + 1]) {
                result += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ++result;
            }
            left = max(left, nums[i]);
        }
        return result;
    }
};
