// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maxScore(vector<int>& nums) {
        const int total = accumulate(cbegin(nums), cend(nums), 0);
        if (size(nums) % 2) {
            return total - ranges::min(nums);
        }
        int mn = numeric_limits<int>::max();
        for (int i = 0; i + 1 < size(nums); ++i) {
            mn = min(mn, nums[i] + nums[i + 1]);
        }
        return total - mn;
    }
};
