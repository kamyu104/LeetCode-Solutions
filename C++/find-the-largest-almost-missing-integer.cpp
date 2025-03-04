// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == size(nums)) {
            return ranges::max(nums);
        }
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        int result = -1;
        if (k == 1) {
            for (const auto& [x, v] : cnt) {
                if (v == 1) {
                    result = max(result, x);
                }
            }
            return result;
        }
        if (cnt[nums[0]] == 1) {
            result = max(result, nums[0]);
        }
        if (cnt[nums.back()] == 1) {
            result = max(result, nums.back());
        }
        return result;
    }
};
