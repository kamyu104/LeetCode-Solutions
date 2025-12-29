// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        int64_t prefix = accumulate(cbegin(nums), cend(nums), 0LL);
        int suffix = numeric_limits<int>::max();
        for (int i = size(nums) - 2; i >= 0; --i) {
            prefix -= nums[i + 1];
            suffix = min(suffix, nums[i + 1]);
            result = max(result, prefix - suffix);
        }
        return result;
    }
};
