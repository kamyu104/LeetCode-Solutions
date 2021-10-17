// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        return max(kadane(nums, 0), kadane(nums, 1));
    }

private:
    int64_t kadane(const vector<int>& nums, int start) {
        int64_t result = numeric_limits<int64_t>::min();
        for (int64_t i = start, curr = 0, odd = 0; i < size(nums); ++i, odd ^= 1) {
            curr = !odd ? curr + nums[i] : max(curr - nums[i], 0L);
            result = max(result, curr);
        }
        return result;
    }
};
