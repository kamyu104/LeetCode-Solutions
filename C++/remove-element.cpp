// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] != val) {
                ++left;
            } else {
                swap(nums[left],  nums[--right]);
            }
        }
        return right;
    }
};
