// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> right(size(nums), 1);
        for (int i = size(nums) - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int result = min(ranges::max(right) + 1, static_cast<int>(size(nums)));
        for (int i = 1, left = 1; i + 1 < size(nums); ++i) {
            if (nums[i - 1] <= nums[i + 1]) {
                result = max(result, left + 1 + right[i + 1]);
            }
            if (nums[i - 1] <= nums[i]) {
                ++left;
            } else {
                left = 1;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> left(size(nums), 1);
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] <= nums[i + 1]) {
                left[i + 1] = left[i] + 1;
            }
        }
        vector<int> right(size(nums), 1);
        for (int i = size(nums) - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int result = min(ranges::max(left) + 1, static_cast<int>(size(nums)));
        for (int i = 1; i + 1 < size(nums); ++i) {
            if (nums[i - 1] <= nums[i + 1]) {
                result = max(result, left[i - 1] + 1 + right[i + 1]);
            }
        }
        return result;
    }
};
