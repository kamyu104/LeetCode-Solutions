// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        // Mark the value as visited by negative.
        for (auto& num : nums) {
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] *= -1;
            } else {
                duplicate = abs(num);
                break;
            }
        }
        // Rollback the value.
        for (auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                nums[abs(num) - 1] *= -1;
            } else {
                break;
            }
        }
        return duplicate;
    }
};
