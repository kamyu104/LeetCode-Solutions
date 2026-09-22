// Time:  O(n)
// Space: O(1)

// prefix sum, hash table
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        int64_t prefix = 0, mn = 0;
        vector<int64_t> lookup = {NEG_INF, 0};
        for (const auto& [i, x] : views::enumerate(nums)) {
            prefix += x * (i % 2 == 0 ? 1 : -1);
            if (lookup[i % 2] != NEG_INF) {
                mn = min(mn, prefix - lookup[i % 2]);
            }
            lookup[i % 2] = max(lookup[i % 2], prefix);
        }
        return prefix - 2 * mn;
    }
};
