// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        vector<int> left(size(nums) + 1, numeric_limits<int>::min());
        for (int i = 0; i < size(nums); ++i) {
            left[i + 1] = max(left[i], nums[i]);
        }
        vector<int> right(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums); i >= 1; --i) {
            right[i - 1] = min(right[i], nums[i - 1]);
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (left[i] <= nums[i] && nums[i] <= right[i + 1]) {
                ++result;
            }
        }
        return result;
    }
};
