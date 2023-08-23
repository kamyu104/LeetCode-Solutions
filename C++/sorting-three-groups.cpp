// Time:  O(k * n) = O(n)
// Space: O(k) = O(1)

// dp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        static const int k = size(nums);

        vector<int> dp(k);
        for (const auto& x : nums) {
            ++dp[x - 1];
            for (int i = x; i < size(dp); ++i) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }
        return size(nums) - dp.back();
    }
};
