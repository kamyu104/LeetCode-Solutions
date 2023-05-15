// Time:  O(nlogn)
// Space: O(1)

// sort, combinatorics, dp
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        int result = 0, dp = 0;
        sort(begin(nums), end(nums));
        for (const int64_t x : nums) {
            result = (result + (((x * x) % MOD) * (dp + x) % MOD)) % MOD;
            dp = (dp + (dp + x)) % MOD;
        }
        return result;
    }
};
