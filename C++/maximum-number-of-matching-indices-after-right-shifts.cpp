// Time:  O(n^2)
// Space: O(1)

// brute force
class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        for (int i = 0; i < size(nums1); ++i) {
            int cnt = 0;
            for (int j = 0; j < size(nums2); ++j) {
                if (nums2[j] == nums1[(i + j) % size(nums1)]) {
                    ++cnt;
                }
            }
            result = max(result, cnt);
        }
        return result;
    }
};
