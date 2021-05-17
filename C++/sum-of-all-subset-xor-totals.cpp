// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // given there are k (k >= 1) nums of which ith bit is 1,
        // the bit contributes to sum is:
        // (nCr(k, 1) + nCr(k, 3) + ...) * (nCr(n - k, 0) + nCr(n - k, 1) + ...) * 2^i
        // = 2^(k-1) * 2^(n-k) = 2^(n-1) * 2^i
        int result = 0;
        for (const auto& x : nums) {
            result |= x;
        }
        return result * pow(2, size(nums) - 1);
    }
};
