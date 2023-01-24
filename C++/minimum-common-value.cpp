// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0, j = 0; i < size(nums1) && j < size(nums2); ) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                return nums1[i];
            }
        }
        return -1;
    }
};
