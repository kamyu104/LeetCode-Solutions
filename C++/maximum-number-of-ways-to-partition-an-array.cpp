// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        const int64_t total = accumulate(begin(nums), end(nums), 0LL);
        unordered_map<int64_t, int> right;
        for (int64_t i = 0, prefix = 0; i < size(nums) - 1; ++i) {
            prefix += nums[i];
            ++right[prefix - (total - prefix)];
        }
        int64_t result = right[0];
        unordered_map<int64_t, int> left;
        int64_t prefix = 0;
        for (const auto& x : nums) {
            result = max(result, static_cast<int64_t>(left[k - x]) + right[-(k - x)]);
            prefix += x;
            --right[prefix - (total - prefix)];
            ++left[prefix - (total - prefix)];
        }
        return result;
    }
};
