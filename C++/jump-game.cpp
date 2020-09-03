// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i <= reachable && i < nums.size(); ++i) {
            reachable = max(reachable, i + nums[i]);
        }
        return reachable >= nums.size() - 1;
    }
};
