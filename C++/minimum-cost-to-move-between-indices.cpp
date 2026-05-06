// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix((size(nums) - 1) + 1);
        for (int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = prefix[i] + (i - 1 == -1 || nums[i + 1] - nums[i] < nums[i] - nums[i - 1] ? 1 : nums[i + 1] - nums[i]);
        }
        vector<int> suffix((size(nums) - 1) + 1);
        for (int i = size(prefix) - 1; i - 1 >= 0; --i) {
            suffix[i - 1] = suffix[i] + (i + 1 == size(nums) || nums[i] - nums[i - 1] <= nums[i + 1] - nums[i] ? 1 : nums[i] - nums[i - 1]);
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& left = queries[i][0], &right = queries[i][1];
            result[i] = (left < right) ? prefix[right] - prefix[left] : suffix[right] - suffix[left];
        }
        return result;
    }
};
