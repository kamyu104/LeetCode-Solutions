// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                if (res.empty() || res.back() != *it1) {
                    res.emplace_back(*it1);
                }
                ++it1, ++it2;
            }
        }
        return res;
    }
};
