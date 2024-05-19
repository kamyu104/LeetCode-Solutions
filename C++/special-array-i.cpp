// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i + 1 < size(nums); ++i) {
            if ((nums[i] & 1) == (nums[i + 1] & 1)) {
                return false;
            }
        }
        return true;
    }
};
