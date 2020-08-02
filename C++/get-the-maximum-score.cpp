// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        static const int MOD = 1e9 + 7;
        uint64_t result = 0, sum1 = 0, sum2 = 0;
        for (int i = 0, j = 0; i != nums1.size() || j != nums2.size();) {
            if (i != nums1.size() && (j == nums2.size() || nums1[i] < nums2[j])) {
                sum1 += nums1[i];
                ++i;
            } else if (j != nums2.size() && (i == nums1.size() || nums1[i] > nums2[j])) {
                sum2 += nums2[j];
                ++j;
            } else {
                result = (result + (max(sum1, sum2) + nums1[i])) % MOD;
                sum1 = sum2 = 0;
                ++i, ++j;
            }
        }
        return (result + max(sum1, sum2)) % MOD;
    }
};
