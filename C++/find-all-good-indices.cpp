// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> left(size(nums), 1);
        for (int i = 1; i + 1 < size(nums); ++i) {
            if (nums[i] <= nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        vector<int> right(size(nums), 1);
        for (int i = size(nums) - 2; i >= 1; --i) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        vector<int> result;
        for (int i = k; i + k < size(nums); ++i) {
            if (min(left[i - 1], right[i + 1]) >= k) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
