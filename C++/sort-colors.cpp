// Time:  O(n)
// Space: O(1)

// Tri-Partition solution.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        static const int target = 1;
        for (int i = 0, left = 0, right = nums.size() - 1; i <= right;) {
            if (nums[i] > target) {
                swap(nums[i], nums[right--]);
            } else {
                if (nums[i] < target) {
                    swap(nums[left++], nums[i]);
                } 
                ++i;
            }
        }
    }
};
