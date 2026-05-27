// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int result = 0;
        for (int i = size(nums) - ranges::count(nums, 0); i < size(nums); ++i) {
            if (nums[i]) {
                ++result;
            }
        }
        return result;
    }
};
