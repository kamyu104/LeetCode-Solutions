// Time:  O(n + logN)
// Space: O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        for (uint64_t miss = 1, i = 0; miss <= n;) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                ++patch;
                miss += miss;
            }
        }
        return patch;
    }
};
