// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
};
