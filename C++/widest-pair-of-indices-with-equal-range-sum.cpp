// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> lookup = {{0, -1}};
        int result = 0, total = 0;
        for (int i = 0; i < size(nums1); ++i) {
            total += nums1[i] - nums2[i];
            if (!lookup.count(total)) {
                lookup[total] = i;
            }
            result = max(result, i - lookup[total]);
        }
        return result;
    }
};
