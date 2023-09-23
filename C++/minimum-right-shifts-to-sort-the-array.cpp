// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int i = 0;
        for (; i < size(nums); ++i) {
            if (!(nums[i % size(nums)] < nums[(i + 1) % size(nums)])) {
                break;
            }
        }
        int j = i + 1;
        for (; j < size(nums); ++j) {
            if (!(nums[j % size(nums)] < nums[(j + 1) % size(nums)])) {
                break;
            }
        }
        return j == size(nums) ? size(nums) - (i + 1) : -1;
    }
};
