// Time:  O(n)
// Space: O(1)

// prefix sum, math
class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int64_t result = numeric_limits<int>::min();
        int64_t prefix = 0, suffix = 0;
        for (int left = 0, right = size(nums) - 1; left < size(nums); ++left, --right) {
            prefix += nums[left];
            suffix += nums[right];
            result = max({result, prefix, suffix});
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// prefix sum
class Solution2 {
public:
    long long maximumSumScore(vector<int>& nums) {
        const int64_t total = accumulate(cbegin(nums), cend(nums), 0ll);
        int64_t result = numeric_limits<int>::min();
        int64_t prefix = 0;
        for (const auto& x : nums) {
            prefix += x;
            result = max({result, prefix, total - prefix + x});
        }
        return result;
    }
};
