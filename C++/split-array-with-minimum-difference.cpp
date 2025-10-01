// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int64_t left = 0, i = 0;
        while (i + 1 < size(nums) && nums[i] < nums[i + 1]) {
            left += nums[i++];
        }
        int64_t right = 0, j = size(nums) - 1;;
        while (j - 1 >= 0 && nums[j] < nums[j - 1]) {
            right += nums[j--];
        }
        if (j - i + 1 >= 3) {
            return -1;
        }
        if (j - i + 1 == 2) {
            return abs((right + nums[j]) - (left + nums[i]));
        }
        return min(abs(right - (left + nums[i])), abs((right + nums[j]) - left));
    }
};
