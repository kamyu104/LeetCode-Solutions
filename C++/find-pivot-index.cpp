// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const auto total = accumulate(nums.begin(), nums.end(), 0);
        auto left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == (total - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};
