// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int64_t result = 0;
        int left = 0;
        vector<int> right(2, -1);
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                left = i + 1;
                continue;
            }
            if (nums[i] == minK) {
                right[0] = i;
            }
            if (nums[i] == maxK) {
                right[1] = i;
            }
            result += max(min(right[0], right[1]) - left + 1, 0);
        }
        return result;
    }
};
