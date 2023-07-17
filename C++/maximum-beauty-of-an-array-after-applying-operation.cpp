// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers, sliding window
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int right = 0, left = 0;
        for (; right < size(nums); ++right) {
            if (nums[right] - nums[left] > k * 2) {
                ++left;
            }
        }
        return right - left;
    }
};
