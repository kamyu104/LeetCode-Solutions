// Time:  O(n)
// Space: O(n)

// counting sort, greedy
class Solution {
public:
    long long maxSum(vector<int>& nums, vector<int>& threshold) {
        vector<vector<int>> groups(size(nums));
        for (int i = 0; i < size(threshold); ++i) {
            groups[threshold[i] - 1].emplace_back(i);
        }
        vector<int> sorted_idxs;
        sorted_idxs.reserve(size(nums));
        for (const auto& g : groups) {
            for (const auto& x : g) {
                sorted_idxs.emplace_back(x);
            }
        }
        int64_t result = 0;
        for (int i = 0; i < size(sorted_idxs); ++i) {
            if (i + 1 < threshold[sorted_idxs[i]]) {
                break;
            }
            result += nums[sorted_idxs[i]];
        }
        return result;
    }
};
