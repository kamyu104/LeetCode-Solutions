// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int cnt = 0;
        for (const auto& x : nums) {
            if (x % 2) {
                continue;
            }
            nums[cnt++] = 0;
        }
        for (; cnt < size(nums); ++cnt) {
            nums[cnt] = 1;
        }
        return nums;
    }
};
