// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int curr = 1, max_count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            curr = (nums[i - 1] <  nums[i]) ? 1 : curr + 1;
            max_count = max(max_count, curr);
        }
        return K * max_count <= nums.size(); 
    }
};
