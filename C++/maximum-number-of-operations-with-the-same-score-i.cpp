// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int result = 1;
        const int target = nums[0] + nums[1];
        for (int i = 2; i + 1 < size(nums); i += 2) {
            if (nums[i] + nums[i + 1] != target) {
                break;
            }
            ++result;
        }
        return result;
    }
};
