// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int64_t result = numeric_limits<int64_t>::min();
        int mx = numeric_limits<int>::min();
        int mn = numeric_limits<int>::max();
        for (int i = 0; i + (m - 1) < size(nums); ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            result = max({result, static_cast<int64_t>(nums[i + (m - 1)]) * mx, static_cast<int64_t>(nums[i + (m - 1)]) * mn});
        }
        return result;
    }
};
