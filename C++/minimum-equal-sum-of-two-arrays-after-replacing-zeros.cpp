// Time:  O(n + m)
// Space: O(1)

// greedy
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const auto& add = [](const auto& accu, const auto& x) {
            return accu + max(x, 1);
        };

        const int64_t total1 = accumulate(cbegin(nums1), cend(nums1), 0ll, add);
        const int64_t total2 = accumulate(cbegin(nums2), cend(nums2), 0ll, add);
        if (total1 < total2) {
            return find(cbegin(nums1), cend(nums1), 0) != cend(nums1) ? total2 : -1;
        }
        if (total1 > total2) {
            return find(cbegin(nums2), cend(nums2), 0) != cend(nums2) ? total1 : -1;
        }
        return total1;
    }
};
