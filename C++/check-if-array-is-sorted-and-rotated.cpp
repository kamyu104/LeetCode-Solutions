// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 0, count = 0; i < size(nums); ++i) {
            if (nums[i] > nums[(i + 1) % size(nums)] && ++count > 1) {
                return false;
            }
        }
        return true;
    }
};
