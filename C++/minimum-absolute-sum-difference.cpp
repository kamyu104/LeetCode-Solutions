// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        static const int MOD = 1e9 + 7;

        vector<int> sorted_nums1(cbegin(nums1), cend(nums1));
        sort(begin(sorted_nums1), end(sorted_nums1));
        int result = 0, max_change = 0;
        for (int i = 0; i < size(nums2); ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            result = (result + diff) % MOD;
            if (diff < max_change) {
                continue;
            }
            const auto cit = lower_bound(cbegin(sorted_nums1), cend(sorted_nums1), nums2[i]);
            if (cit != cend(sorted_nums1)) {
                max_change = max(max_change, diff - abs(*cit - nums2[i]));
            }
            if (cit != cbegin(sorted_nums1)) {
                max_change = max(max_change, diff - abs(*prev(cit) - nums2[i]));
            }
        }
        return (result - max_change + MOD) % MOD;
    }
};
