// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> top2(2, numeric_limits<int>::max());
        for (int i = 1; i < size(nums); ++i) {
            for (auto& x : top2) {
                if (nums[i] < x) {
                    swap(x, nums[i]);
                }
            }
        }
        return nums[0] + top2[0] + top2[1];
    }
};
