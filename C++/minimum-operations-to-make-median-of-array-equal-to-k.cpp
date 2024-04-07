// Time:  O(n)
// Space: O(1)

// quick select, greedy
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + size(nums) / 2, end(nums));
        int64_t result = 0;
        for (int i = 0; i <= size(nums) / 2; ++i) {
            result += max(nums[i] - k, 0);
        }
        for (int i = size(nums) / 2; i < size(nums); ++i) {
            result += max(k - nums[i], 0);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, greedy
class Solution2 {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int64_t result = 0;
        for (int i = 0; i <= size(nums) / 2; ++i) {
            result += max(nums[i] - k, 0);
        }
        for (int i = size(nums) / 2; i < size(nums); ++i) {
            result += max(k - nums[i], 0);
        }
        return result;
    }
};
