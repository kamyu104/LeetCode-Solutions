// Time:  O(n)
// Space: O(n)

// freq table, two pointers, sliding window
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> nums_set(cbegin(nums), cend(nums));
        int result = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < size(nums); ++right) {
            ++cnt[nums[right]];
            for (; size(cnt) == size(nums_set); ++left) {
                if (--cnt[nums[left]] == 0) {
                    cnt.erase(nums[left]);
                }
            }
            result += left;
        }
        return result;
    }
};
