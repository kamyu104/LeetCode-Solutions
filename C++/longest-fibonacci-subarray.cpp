// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 2;
        for (int i = 2, cnt = 2; i < size(nums); ++i) {
            if (nums[i] != nums[i - 1] + nums[i - 2]) {
                cnt = 2;
                continue;
            }
            result = max(result, ++cnt);
        }
        return result;
    }
};
