// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        if (find(cbegin(nums), cend(nums), 0) != cend(nums)) {
            return 1;
        }
        int result = size(nums);
        int64_t curr = nums[0];
        for (int i = 1; i < size(nums); ++i) {
            if (curr * nums[i] > k) {
                curr = nums[i];
            } else {
                curr *= nums[i];
                --result;
            }
        }
        return result;
    }
};
