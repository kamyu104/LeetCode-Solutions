// Time:  O(n)
// Space: O(k)

// two pointers
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int64_t result = 0, left = 0, total = 0;
        unordered_set<int> lookup;
        for (int64_t right = 0; right < size(nums); ++right) {
            for (; lookup.count(nums[right]) || size(lookup) == k; ++left) {
                lookup.erase(nums[left]);
                total -= nums[left];
            }
            lookup.emplace(nums[right]);
            total += nums[right];
            if (size(lookup) == k) {
                result = max(result, total);
            }
        }
        return result;
    }
};
