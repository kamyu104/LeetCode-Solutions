// Time:  O(n)
// Space: O(1)

// array, inplace
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i = 0;
        for (const auto& x : nums) {
            if (i - k >= 0 && nums[i - k] == x) {
                continue;
            }
            nums[i++] = x;
        }
        nums.resize(i);
        return nums;
    }
};
