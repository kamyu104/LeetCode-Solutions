// Time:  O(n^2)
// Space: O(n)

// greedy, sort, dp, linear search
class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        vector<int> idx(size(nums1));
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](const auto& a, const auto& b) {
            return nums2[a] < nums2[b];
        });
        vector<int> dp(size(nums1) + 1);
        for (int i = 0; i < size(idx); ++i) {
            const auto& a = nums1[idx[i]], &b = nums2[idx[i]];
            for (int j = i + 1; j >= 1; --j) {
                dp[j] = max(dp[j], dp[j - 1] + (a + j * b));
            }
        }
        const auto& total1 = accumulate(cbegin(nums1), cend(nums1), 0);
        const auto& total2 = accumulate(cbegin(nums2), cend(nums2), 0);
        for (int j = 0; j < size(dp); ++j) {
            if ((total1 + j * total2) - dp[j] <= x) {
                return j;
            }
        }
        return -1;
    }
};
