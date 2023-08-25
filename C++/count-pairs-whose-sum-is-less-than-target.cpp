// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int result = 0;
        int left = 0, right = size(nums) - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                result += right - left;
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};
