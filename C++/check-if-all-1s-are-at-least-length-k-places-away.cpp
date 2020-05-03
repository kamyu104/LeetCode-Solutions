// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -k - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                continue;
            }
            if (i - prev <= k) {
                return false;
            }
            prev = i;
        }
        return true;
    }
};
