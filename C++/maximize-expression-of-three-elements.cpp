// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        const int i = distance(cbegin(nums), max_element(cbegin(nums), cend(nums)));
        swap(nums[i], nums[size(nums) - 1]);
        const int j = distance(cbegin(nums), max_element(cbegin(nums), cbegin(nums) + (size(nums) - 1)));
        swap(nums[j], nums[size(nums) - 2]);
        const int k = distance(cbegin(nums), min_element(cbegin(nums), cbegin(nums) + (size(nums) - 2)));
        swap(nums[k], nums[0]);
        return nums[size(nums) - 1] + nums[size(nums) - 2] - nums[0];
    }
};
