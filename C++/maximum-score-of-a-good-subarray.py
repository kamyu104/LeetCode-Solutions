// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int result = nums[k], curr = nums[k];
        int left = k, right = k;
        while (left - 1 >= 0 || right + 1 < size(nums)) {
            int l = (left - 1 >= 0 ? nums[left - 1] : 0);
            int r = (right + 1 < size(nums) ? nums[right + 1] : 0);
            if (l < r) { // choosing larger one to expand is always better than or equal to choosing smaller one
                ++right;
            } else {
                --left;
            }
            curr = min({curr, nums[left], nums[right]});
            result = max(result, curr * (right - left + 1));
        }
        return result;
    }
};
