// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> result(2);
        for (int i = 0; i < nums.size(); ++i) {
            const auto& left = (i - 1 >= 0) ? nums[i - 1] : numeric_limits<int>::max();
            const auto& right = (i + 1 < nums.size()) ? nums[i + 1] : numeric_limits<int>::max();
            result[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }
        return *min_element(result.cbegin(), result.cend());
    }
};
