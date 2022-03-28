// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (i % 2 == result % 2 && nums[i] == nums[i + 1]) {
                ++result;
            }
        }
        return result + (size(nums) - result) % 2;
    }
};
