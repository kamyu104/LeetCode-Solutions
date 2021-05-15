// Time:  O(n + m)
// Space: O(1)

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int result = 0, i = 0, j = 0;
        while (i < size(nums1) && j < size(nums2)) {
            if (nums1[i] > nums2[j]) {
                ++i;
            } else {
                result = max(result, j - i);
                ++j;
            }
        }
        return result;
    }
};
