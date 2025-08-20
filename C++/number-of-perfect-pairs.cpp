// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers, math
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            nums[i] = abs(nums[i]);
        }
        sort(begin(nums), end(nums));
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            for (; !(nums[right] - nums[left] <= nums[left]); ++left);
            result += (right - left + 1) - 1;
        }
        return result;
    }
};
