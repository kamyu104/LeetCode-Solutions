// Time:  O(sqrt(n))
// Space: O(1)

// number theory
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int result = 0;
        const int sqrt_n = sqrt(size(nums));
        for (int i = 1; i <= sqrt_n; ++i) {
            if (size(nums) % i) {
                continue;
            }
            result += nums[i - 1] * nums[i - 1];
            if (size(nums) / i != i) {
                result += nums[size(nums) / i - 1] * nums[size(nums) / i - 1];
            }
        }
        return result;
    }
};
