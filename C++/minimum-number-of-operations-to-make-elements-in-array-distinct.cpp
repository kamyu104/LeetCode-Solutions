// Time:  O(n + r)
// Space: O(r)

// freq table
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const int mx = ranges::max(nums);
        vector<int> cnt(mx);
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (++cnt[nums[i] - 1] == 2) {
                return ceil_divide(i + 1, 3);
            }
        }
        return 0;
    }
};
