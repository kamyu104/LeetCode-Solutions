// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const auto& max_num = *max_element(nums.cbegin(), nums.cend());
        if (max_num < 0) {
            return max_num;
        }
        int global_max = 0, local_max = 0;
        for (const auto &x : nums) {
           local_max = std::max(0, local_max + x);
           global_max = std::max(global_max, local_max);
        }
        return global_max;
    }
};
