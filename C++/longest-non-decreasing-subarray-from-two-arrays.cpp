// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 1;
        vector<int> dp(2, 1);
        for (int i = 0; i + 1 < size(nums1); ++i) {
            dp = {max(nums1[i] <= nums1[i + 1] ? dp[0] + 1 : 1, nums2[i] <= nums1[i + 1] ? dp[1] + 1 : 1),
                  max(nums1[i] <= nums2[i + 1] ? dp[0] + 1 : 1, nums2[i] <= nums2[i + 1] ? dp[1] + 1 : 1)};
            result = max(result, max(dp[0], dp[1]));
        }
        return result;
    }
};
