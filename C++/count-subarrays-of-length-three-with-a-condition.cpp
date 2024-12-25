// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i + 1 < size(nums); ++i) {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ++result;
            }
        }
        return result;
    }
};
