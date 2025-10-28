// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int64_t result = 0;
        int cnt = numeric_limits<int>::max();
        for (int i = 0; i < size(nums1); ++i) {
            result += abs(nums1[i] - nums2[i]);
            if (static_cast<int64_t>(nums2.back() - nums1[i]) * (nums2.back() - nums2[i]) <= 0) {
                cnt = 0;
            }
            cnt = min({cnt, abs(nums2.back() - nums1[i]), abs(nums2.back() - nums2[i])});
        }
        result += 1 + cnt;
        return result;
    }
};
