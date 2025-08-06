// Time:  O(n)
// Space: O(n)

// freq table, two pointers
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int left = 0;
        for (int right = 0, repeat = 0; right < size(nums); ++right) {
            if (++cnt[nums[right]] == 2) {
                ++repeat;
            }
            if (repeat > k) {
                if (cnt[nums[left]]-- == 2) {
                    --repeat;
                }
                if (!cnt[nums[left]]) {
                    cnt.erase(nums[left]);
                }
                ++left;
            }
        }
        return size(nums) - left;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table, two pointers
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int result = 0;
        for (int right = 0, left = 0, repeat = 0; right < size(nums); ++right) {
            if (++cnt[nums[right]] == 2) {
                ++repeat;
            }
            while (repeat > k) {
                if (cnt[nums[left]]-- == 2) {
                    --repeat;
                }
                if (!cnt[nums[left]]) {
                    cnt.erase(nums[left]);
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
