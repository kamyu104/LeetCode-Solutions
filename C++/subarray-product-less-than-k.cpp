// Time:  O(n)
// Space: O(1)

// Sliding window solution.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int result = 0, start = 0, prod = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[start];
                ++start;
            }
            result += i - start + 1;
        }
        return result;
    }
};
