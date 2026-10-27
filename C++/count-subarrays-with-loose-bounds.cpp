// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (!(minK <= nums[right] && nums[right] <= maxK)) {
                left = right + 1;
                continue;
            }
            result += right - left + 1;
        }
        return result;
    }
};
