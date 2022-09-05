// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int64_t result = 0, left = 0;
        for (int64_t right = 0; right < size(nums); ++right) {
            if (!(right - 1 >= 0 && nums[right - 1] < nums[right])) {
                left = right;
            }
            result += right - left + 1;
        }
        return result;
    }
};
