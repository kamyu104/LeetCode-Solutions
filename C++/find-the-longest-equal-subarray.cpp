// Time:  O(n)
// Space: O(n)

// freq table, two pointers, sliding window
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            result = max(result, ++cnt[nums[right]]);
            if (right - left + 1 > result + k) {
                --cnt[nums[left++]];
            }
        }
        return result;
    }
};
