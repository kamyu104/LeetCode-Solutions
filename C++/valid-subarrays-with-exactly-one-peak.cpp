// Time:  O(n)
// Space: O(1)

// combinatorics, two pointers
class Solution {
public:
    long long validSubarrays(vector<int>& nums, int k) {
        int64_t result = 0, left = -1, l = 0;
        for (int64_t right = 1; right + 1 < size(nums); ++right) {
            if (!(nums[right - 1] < nums[right] && nums[right] > nums[right + 1])) {
                continue;
            }
            const auto& r = min(right - left, static_cast<int64_t>(k + 1));
            result += l * r;
            left = right;
            l = r;
        }
        result += l * min(static_cast<int64_t>(size(nums)) - left, static_cast<int64_t>(k + 1));
        return result;
    }
};
