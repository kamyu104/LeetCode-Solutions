// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(robRange(nums, 0, nums.size() - 1), // Include the first one of nums without the last one.
                   robRange(nums, 1, nums.size()));    // Include the last one of nums without the first one.
    }

    int robRange(vector<int>& nums, int start, int end) {
        int num_i = nums[start], num_i_1 = 0, num_i_2 = 0;
        for (int i = start + 1; i < end; ++i) {
            num_i_2 = num_i_1;
            num_i_1 = num_i;
            num_i = max(nums[i] + num_i_2, num_i_1);
        }
        return num_i;
    }
};
