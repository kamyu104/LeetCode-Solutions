// Time:  O(n)
// Space: O(n)

// math, freq table
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (size(nums) % k) {
            return false;
        }
        const int group_cnt = size(nums) / k;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            if (++cnt[x] > group_cnt) {
                return false;
            }
        }
        return true;
    }
};
