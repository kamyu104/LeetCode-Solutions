// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        static const int NEG_INF = numeric_limits<int>::min();

        int result = NEG_INF, prefix = NEG_INF;
        for (int i = 0; i + k < size(nums); ++i) {
            prefix = max(prefix, nums[i]);
            result = max(result, prefix + nums[i + k]);
        }
        return result;
    }
};
