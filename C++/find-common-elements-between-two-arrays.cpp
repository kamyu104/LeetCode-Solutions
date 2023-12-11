// Time:  O(n + m)
// Space: O(n + m)

// hash table
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> lookup1(cbegin(nums1), cend(nums1));
        unordered_set<int> lookup2(cbegin(nums2), cend(nums2));
        return {
            static_cast<int>(count_if(cbegin(nums1), cend(nums1), [&](const auto& x) {
                return lookup2.count(x);
            })),
            static_cast<int>(count_if(cbegin(nums2), cend(nums2), [&](const auto& x) {
                return lookup1.count(x);
            }))
        };
    }
};
