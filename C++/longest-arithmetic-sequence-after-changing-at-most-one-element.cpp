// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        const auto& f = [](const auto& nums) {
            int result = 2;
            for (int right = 2, left = 0, diff = nums[1] - nums[0]; right < size(nums); ++right) {
                const auto& curr = nums[right] - nums[right - 1];
                if (curr == diff) {
                    result = max(result, right - left + 1);
                    continue;
                }
                int r = right;
                while (r + 1 < size(nums) && nums[r + 1] - (r != right ? nums[r] : nums[right - 1] + diff) == diff) {
                    ++r;
                }
                result = max(result, r - left + 1);
                left = right - 1;
                diff = curr;
            }
            return result;
        };

        int result = f(nums);
        ranges::reverse(nums);
        result = max(result, f(nums));
        return result;
    }
};
