// Time:  O(m * n) on average
// Space: O(m * n)

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (const auto& row : grid) {
            nums.insert(end(nums), cbegin(row), cend(row));
        }
        int mod_group = -1;
        for (const auto& num : nums) {
            if (mod_group == -1) {
                mod_group = num % x;
            } else if (mod_group != num % x) {
                return -1;
            }
        }
        nth_element(begin(nums), begin(nums) + size(nums) / 2, end(nums));
        const auto& median = nums[size(nums) / 2];
        return accumulate(cbegin(nums), cend(nums), 0,
                          [&median, &x](const auto& total, const auto& a) {
                              return total + abs(a - median) / x;
                          });
    }
};
