// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int64_t total = accumulate(cbegin(nums), cend(nums), 0ll);
        int64_t mn = numeric_limits<int64_t>::max(), idx = -1;
        int64_t prefix = 0;
        for (int i = 0; i < size(nums); ++i) {
            prefix += nums[i];
            const int a = prefix / (i + 1);
            const int b = i + 1 < size(nums) ? (total - prefix) / (size(nums) - (i + 1)) : 0;
            const int diff = abs(a - b);
            if (diff < mn) {
                mn = diff;
                idx = i;
            }
        }
        return idx;
    }
};
