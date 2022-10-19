// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        const auto& ceil_divide = [](int64_t a, int b) {
            return static_cast<int>((a + b - 1) / b);
        };

        int result = 0;
        int64_t curr = 0;
        for (int i = 0; i < size(nums); ++i) {
            curr += nums[i];
            result = max(result, ceil_divide(curr, i + 1));
        }
        return result;
    }
};
