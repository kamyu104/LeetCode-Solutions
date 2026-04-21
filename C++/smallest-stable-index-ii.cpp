// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> right(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int left = 0;
        for (int i = 0; i < size(nums); ++i) {
            left = max(left, nums[i]);
            if (left - right[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> left(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            left[i + 1] = max(left[i], nums[i]);
        }
        vector<int> right(size(nums) + 1, numeric_limits<int>::max());
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        for (int i = 0; i < size(nums); ++i) {
            if (left[i + 1] - right[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
