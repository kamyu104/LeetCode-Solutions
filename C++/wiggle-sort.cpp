// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (((i % 2) && nums[i] < nums[i - 1]) ||
                (!(i % 2) && nums[i] > nums[i - 1])) {
                // Swap unordered elements.
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
