// Time:  O(n^2 * 2^n)
// Space: O(2^n)

class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << size(nums));
        for (int mask = 3; mask < size(dp); ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2) {
                continue;
            }
            vector<int> bits;
            for (int i = 0, m = mask; m; ++i, m >>= 1) {
                if (m & 1) {
                    bits.emplace_back(i);
                }
            }
            for (int i = 0; i < size(bits); ++i) {
                for (int j = i + 1; j < size(bits); ++j) {
                    dp[mask] = max(dp[mask], cnt / 2 * gcd(nums[bits[i]], nums[bits[j]]) + dp[mask ^ (1 << bits[i]) ^ (1 << bits[j])]);
                }
            }
        }
        return dp.back();
    }
};
