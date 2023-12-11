// Time:  O(n)
// Space: o(n)

// freq table, two pointers, sliding window
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            ++cnt[nums[right]];
            while (!(cnt[nums[right]] <= k)) {
                --cnt[nums[left++]];
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
