// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int result = 0;
        for (int i = 0, left = 0, right = accumulate(cbegin(nums), cend(nums), 0);
             i + 1 < size(nums); ++i) {
            right -= nums[i];
            left += nums[i];
            if (left % 2 == right % 2) {
                ++result;
            }
        }
        return result;
    }
};
