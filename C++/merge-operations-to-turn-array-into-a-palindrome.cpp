// Time:  O(n)
// Space: O(1)

// constructive algorithms, greedy, two pointers
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        int left = -1, right = size(nums);
        int64_t l = nums[++left], r = nums[--right];
        while (left < right) {
            if (l == r) {
                l = nums[++left];
                r = nums[--right];
                continue;
            }
            if (l < r) {
                l += nums[++left];
            } else {
                r += nums[--right];
            }
            ++result;
        }
        return result;
    }
};
