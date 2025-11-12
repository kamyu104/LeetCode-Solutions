// Time:  O(n)
// Space: O(n)

// prefix sum, freq table
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int64_t> cnt((2 * size(nums) + 1) + 1);
        vector<int64_t> prefix((2 * size(nums) + 1) + 1);
        prefix[size(nums) + 1] = cnt[size(nums) + 1] = 1;
        int64_t result = 0, curr = size(nums) + 1;
        for (const auto& x : nums) {
            curr += (x == target) ? +1 : -1;
            ++cnt[curr];
            prefix[curr] = prefix[curr - 1] + cnt[curr];
            result += prefix[curr - 1];
        }
        return result;
    }
};
