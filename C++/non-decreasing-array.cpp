// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1, prev = nums[0]; i < nums.size(); ++i) {
            if (prev > nums[i]) {
                if (cnt++) {
                    return false;
                }
                if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
                    prev = nums[i];      // nums[i - 1] = nums[i], prev = nums[i]
//              } else {
//                  prev = nums[i - 1];  // nums[i] = nums[i - 1], prev = nums[i]
                }
            } else {
                prev = nums[i];
            }
        }
        return true;
    }
};
