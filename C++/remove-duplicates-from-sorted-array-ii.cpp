// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const int k = 2; // At most k duplicated.

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] != nums[right] ||
                (left - k + 1 < 0 || nums[left] != nums[left - k + 1])) {
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }

        return left + 1; 
    }
};
