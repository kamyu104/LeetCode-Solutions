// Time:  O(s + logn), s is the number of elements in the array
// Space: O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        for (uint64_t miss = 1, i = 0; miss <= n;) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++patch;
            }
        }
        return patch;
    }
};
