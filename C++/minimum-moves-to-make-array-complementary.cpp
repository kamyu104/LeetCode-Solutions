// Time:  O(n + k)
// Space: O(k)

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * (limit + 1));
        for (int i = 0; i < size(nums) / 2; ++i) {
            int left = nums[i], right = nums[size(nums) - 1 - i];
            --diff[min(left, right) + 1];                   // if target total grows to min(left, right)+1, one less move
            --diff[left + right];                           // if target total grows to left+right, one less move
            ++diff[left + right + 1];                       // if target total grows to left+right+1, one more move
            ++diff[max(left, right) + limit + 1];           // if target total grows to max(left, right)+limit+1, one more move
        }
        int result = size(nums), count = size(nums);        // default is to move all nums
        for (int total = 2; total <= limit * 2; ++total) {  // enumerate all possible target totals
            count += diff[total];
            result = min(result, count);
        }
        return result;
    }
};
