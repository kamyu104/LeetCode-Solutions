// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int j = size(nums) - 1;
        for (; j >= 1; --j) {
            if (!(nums[j - 1] < nums[j])) {
                break;
            }
        }
        if (j == 0) {
            return (size(nums) + 1) * size(nums) / 2;
        }
        int64_t result = size(nums) - j + 1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            while (j < size(nums) && !(nums[i] < nums[j])) {
                ++j;
            }
            result += size(nums) - j + 1;
            if (!(nums[i] < nums[i + 1])) {
                break;
            }
        }
        return result;
    }
};
