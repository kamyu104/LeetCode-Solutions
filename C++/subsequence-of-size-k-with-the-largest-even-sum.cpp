// Time:  O(n) on overage
// Space: O(1)

// quick select solution
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + k, end(nums), greater<int>());
        int64_t total = accumulate(begin(nums), begin(nums) + k, 0ll);
        if (total % 2 == 0) {
            return total;
        }
        vector<int> min_k(2, numeric_limits<int>::max());
        for (int i = 0; i < k; ++i) {
            min_k[nums[i] % 2] = min(min_k[nums[i] % 2], nums[i]);
        }
        int64_t result = -1;
        for (int i = k; i < size(nums); ++i) {
            result = max(result, total - min_k[!(nums[i] % 2)] + nums[i]);
        }
        return result;
    }
};
