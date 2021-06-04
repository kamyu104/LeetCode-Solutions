// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < size(nums1); ++i) {
            nums1[i] -= nums2[i];
        }
        sort(begin(nums1), end(nums1));
        long long result = 0;
        int left = 0, right = size(nums1) - 1;
        while (left < right) {
            if (nums1[left] > 0 || -nums1[left] < nums1[right]) {
                result += right - left;
                --right;
            } else {
                ++left;
            }
        }
        return result;
    }
};
