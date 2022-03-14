// Time:  O(min(n, k))
// Space: O(1)

// constructive algorithms
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (size(nums) == 1 && k % 2 == 1) {
            return -1;
        }
        if (k <= 1) {
            return nums[k];
        }
        int result = 0;
        for (int i = 0; i < min(k + 1, static_cast<int>(size(nums))); ++i) {
            if (i != k - 1) {
                result = max(result, nums[i]);
            }
        }
        return result;
    }
};
