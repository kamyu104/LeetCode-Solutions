// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < size(nums1) || j < size(nums2)) {
            if (j == size(nums2) || (i < size(nums1) && nums1[i][0] < nums2[j][0])) {
                if (!empty(result) && result.back()[0] == nums1[i][0]) {
                    result.back()[1] += nums1[i][1];
                } else {
                    result.emplace_back(nums1[i]);
                }
                ++i;
            } else {
                if (!empty(result) && result.back()[0] == nums2[j][0]) {
                    result.back()[1] += nums2[j][1];
                } else {
                    result.emplace_back(nums2[j]);
                }
                ++j;
            }
        }
        return result;
    }
};
