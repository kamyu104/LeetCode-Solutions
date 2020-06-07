// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        static const auto& dest = [](int i, int n) {
            return (i < n) ? 2 * i : 2 * (i - n) + 1;
        };
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            int j = i;
            do {
                j = dest(j, n);
                swap(nums[i], nums[j]);
                nums[j] = -nums[j];
            } while (j != i);
        }
        for (auto& num : nums) {
            num = -num;
        }
        return nums;
    }
};
