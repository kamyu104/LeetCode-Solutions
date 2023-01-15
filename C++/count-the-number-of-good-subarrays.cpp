// Time:  O(n)
// Space: O(n)

// two pointers, sliding window
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int64_t result = 0, curr = 0;
        unordered_map<int, int> cnt;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            curr += cnt[nums[right]]++;
            while (curr >= k) {
                curr -= --cnt[nums[left++]];
            }
            result += left;
        }
        return result;
    }
};
