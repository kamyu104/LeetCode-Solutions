// Time:  O(n + q)
// Space: O(n)

// line sweep
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> events(size(nums) + 1);
        for (const auto& q : queries) {
            ++events[q[0]];
            --events[q[1] + 1];
        }
        for (int i = 0, curr = 0; i < size(nums); ++i) {
            curr += events[i];
            if (nums[i] > curr) {
                return false;
            }
        }
        return true;
    }
};
