// Time:  O(n)
// Space: O(n)

// prefix sum, greedy
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> right(size(nums) + 1);
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = right[i + 1] | nums[i];
        }
        int64_t result = 0;
        int left = 0;
        for (int i = 0; i < size(nums); ++i) {
            result = max(result, left | (static_cast<int64_t>(nums[i]) << k) | right[i + 1]);
            left |= nums[i];
        }
        return result;
    }
};
