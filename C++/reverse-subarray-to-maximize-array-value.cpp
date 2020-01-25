// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int result = 0, add = 0;
        int max_pair = numeric_limits<int>::min(), min_pair = numeric_limits<int>::max();
        for (int i = 1; i < nums.size(); ++i) {
            result += abs(nums[i-1] - nums[i]);
            add = max({add,
                       abs(nums[0] - nums[i]) - abs(nums[i - 1] - nums[i]),
                       abs(nums.back() - nums[i - 1]) - abs(nums[i - 1] - nums[i])});
            min_pair = min(min_pair, max(nums[i - 1], nums[i]));
            max_pair = max(max_pair, min(nums[i - 1], nums[i]));
        }
        return result + max(add, (max_pair - min_pair) * 2);
    }
};
