// Time:  O(n)
// Space: O(1)

// combinatorics
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        static const int MOD = 1e9 + 7;
        int result = 1, prev = -1;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != 1) {
                continue;
            }
            if (prev != -1) {
                result = (result * static_cast<int64_t>(i - prev)) % MOD;
            }
            prev = i;
        }
        return prev != -1 ? result : 0;
    }
};
