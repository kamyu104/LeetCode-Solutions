// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            return maxDotProduct(nums2, nums1);
        }
        vector<vector<int64_t>> dp(2, vector<int64_t>(nums2.size()));
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                dp[i % 2][j] = int64_t(nums1[i]) * nums2[j];
                if (i && j) {
                    dp[i % 2][j] += max(dp[(i - 1) % 2][j - 1], int64_t(0));
                }
                if (i) {
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
                }
                if (j) {
                    dp[i % 2][j] = max(dp[i % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[(nums1.size() - 1) % 2].back();
    }
};
