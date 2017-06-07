// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const auto n = nums.size();
        auto left = -1, right = -2;
        auto max_from_left = nums[0], min_from_right = nums.back();
        for (int i = 1; i < n; ++i) {
            max_from_left = max(max_from_left, nums[i]);
            min_from_right = min(min_from_right, nums[n - 1 - i]);
            if (nums[i] < max_from_left) {
                right = i;
            }
            if (nums[n - 1 - i] > min_from_right) {
                left = n - 1 - i;
            }
        }
        return right - left + 1;
    }
};
