// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return ranges::max(nums2) - ranges::max(nums1);
    }
};
