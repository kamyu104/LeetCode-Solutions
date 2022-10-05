// Time:  O(n)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        if (size(nums2) % 2) {
            result ^= accumulate(cbegin(nums1), cend(nums1), 0, [](const auto& x, const auto& y) { return x ^ y; });
        }
        if (size(nums1) % 2) {
            result ^= accumulate(cbegin(nums2), cend(nums2), 0, [](const auto& x, const auto& y) { return x ^ y; });
        }
        return result;
    }
};
