// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return static_cast<int64_t>(k) * (ranges::max(nums) - ranges::min(nums));
    }
};
