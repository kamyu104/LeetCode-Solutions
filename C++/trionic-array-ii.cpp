// Time:  O(n)
// Space: O(1)

// two pointers, greedy
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        for (int64_t right = 1, left = 0, p = 0, q = 0, prefix = nums[0]; right < size(nums); ++right) {
            prefix += nums[right];
            if (nums[right - 1] > nums[right]) {
                if (right - 2 >= 0 && nums[right - 2] < nums[right - 1]) {
                    p = right - 1;
                    while (left < q || (nums[left] < 0 && left + 1 < p)) {
                        prefix -= nums[left++];
                    }
                }
            } else if (nums[right - 1] < nums[right]) {
                if (right - 2 >= 0 && nums[right - 2] > nums[right - 1]) {
                    q = right - 1;
                }
                if (left != p) {
                    result = max(result, prefix);
                }
            } else {
                left = p = q = right;
                prefix = nums[right];
            }
        }
        return result;
    }
};
