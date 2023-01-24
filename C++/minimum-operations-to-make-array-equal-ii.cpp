// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int64_t cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < size(nums1); ++i) {
            if (nums1[i] == nums2[i]) {
                continue;
            }
            if (k == 0 || (nums1[i] - nums2[i]) % k) {
                return -1;
            }
            if (nums1[i] < nums2[i]) {
                cnt1 += static_cast<int64_t>(nums2[i] - nums1[i]) / k;
            } else {
                cnt2 += static_cast<int64_t>(nums1[i] - nums2[i]) / k;
            }
        }
        return cnt1 == cnt2 ? cnt1 : -1;
    }
};
