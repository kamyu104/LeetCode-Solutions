// Time:  O(n)
// Space: O(1)

// prefix sum, greedy
class Solution {
public:
    int makeArrayPositive(vector<int>& nums) {
        using int128_t = __int128;
        static const int64_t MAX_VAL = 1e18;

        int result = 0;
        int128_t prev1 = nums[0] + nums[1];
        int128_t prev2 = nums[0];
        int128_t max_prev3 = 0;
        for (int i = 2; i < size(nums); ++i) {
            int128_t prefix = prev1 + nums[i];
            if (prefix - max_prev3 <= 0) {
                prefix = prev1 + MAX_VAL;
                ++result;
            }
            max_prev3 = max(max_prev3, prev2);
            prev2 = prev1;
            prev1 = prefix;
        }
        return result;
    }
};
