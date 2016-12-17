// Time:  O(n) on average
// Space: O(1)

// Quick select solution.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto it = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), it, nums.end());
        const auto median = *it;
        int result = 0;
        for (const auto &i : nums) {
            result += abs(i - median);
        }
        return result;
    }
};
