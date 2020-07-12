// Time:  O(n + klogk)
// Space: O(1)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        static const int k = 4;
        if (nums.size() <= k) {
            return 0;
        }
        nth_element(begin(nums), begin(nums) + k, end(nums));
        sort(begin(nums), begin(nums) + k);
        nth_element(begin(nums) + k, max(begin(nums) + k, end(nums) - k), end(nums));
        sort(end(nums) - k, end(nums));
        int result = numeric_limits<int>::max();
        for (int i = 0; i < k; ++i) {
            result = min(result, nums[nums.size() - k + i] - nums[i]);
        }
        return result;
    }
};
