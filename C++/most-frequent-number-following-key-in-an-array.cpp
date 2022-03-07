// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] == key && cnt[result] < ++cnt[nums[i + 1]]) {
                result = nums[i + 1];
            }
        }
        return result;
    }
};
