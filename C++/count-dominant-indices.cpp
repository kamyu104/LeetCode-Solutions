// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int result = 0, total = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (i * nums[(size(nums) - 1) - i] > total) {
                ++result;
            }
            total += nums[(size(nums) - 1) - i];
        }
        return result;
    }
};
