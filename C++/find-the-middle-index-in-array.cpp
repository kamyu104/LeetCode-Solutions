// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        const int total = accumulate(cbegin(nums), cend(nums), 0);
        int accu = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (accu * 2 == total - nums[i]) {
                return i;
            }
            accu += nums[i];
        }
        return -1;
    }
};
