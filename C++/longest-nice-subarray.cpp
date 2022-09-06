// Time:  O(n)
// Space: O(1)

// sliding window, two pointers
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 0;
        for (int right = 0, left = 0, curr = 0; right < size(nums); ++right) {
            while (curr & nums[right]) {
                curr ^= nums[left++];
            }
            curr |= nums[right];
            result = max(result, right - left + 1);
        }
        return result;
    }
};
