// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> lookup;
        int prefix[size(nums) + 1];
        int result = 0, left = 0;
        for (int right = 0; right < size(nums); ++right) {
            prefix[right + 1] = prefix[right] + nums[right];
            if (lookup.count(nums[right])) {
                left = max(left, lookup[nums[right]] + 1);
            }
            lookup[nums[right]] = right;
            result = max(result, prefix[right + 1] - prefix[left]);
        }
        return result;
    }
};
