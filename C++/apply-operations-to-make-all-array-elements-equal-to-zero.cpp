// Time:  O(n)
// Space: O(1)

// greedy, sliding window
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int curr = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] - curr < 0) {
                return false;
            }
            nums[i] -= curr;
            curr += nums[i];
            if (i - (k - 1) >= 0) {
                curr -= nums[i - (k - 1)];
            }
        }
        return curr == 0;
    }
};
