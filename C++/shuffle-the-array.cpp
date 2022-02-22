// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        static const auto& index = [&n](int i) {
            return (i < n) ? 2 * i : 2 * (i - n) + 1;
        };
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            while (nums[i] >= 0) {
                j = index(j);
                tie(nums[i], nums[j]) = pair(nums[j], ~nums[i]);
            }
        }
        for (auto& num : nums) {
            num = ~num;
        }
        return nums;
    }
};
