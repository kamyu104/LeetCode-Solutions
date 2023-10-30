// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        static const int W = 3;

        vector<int64_t> dp(W);
        for (int i = 0; i < size(nums); ++i) {
            int64_t mn = numeric_limits<int64_t>::max();
            for (int j = i - W; j < i; ++j) {
                mn = min(mn, dp[(j % W + W) % W]);
            }
            dp[i % W] = mn + max(k - nums[i], 0);
        }
        return *min_element(cbegin(dp), cend(dp));
    }
};
