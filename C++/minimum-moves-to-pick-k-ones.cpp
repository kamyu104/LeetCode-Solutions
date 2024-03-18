// Time:  O(n)
// Space: O(n)

// prefix sum, greedy
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> idxs;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i]) {
                idxs.emplace_back(i);
            }
        }
        vector<int64_t> prefix(size(idxs) + 1);
        for (int i = 0; i < size(idxs); ++i) {
            prefix[i + 1] = prefix[i] + idxs[i];
        }
        const int cnt = max(k - maxChanges, 0);
        const int bound = min({cnt + 3, k, static_cast<int>(size(idxs))});
        int64_t result = numeric_limits<int64_t>::max();
        for (int l = cnt; l <= bound; ++l) {
            const auto cnt1 = (k - l) * 2;
            for (int i = 0; i + l < size(prefix); ++i) {
                const auto cnt2 = (prefix[(i + l - 1) + 1] - prefix[(i + l - 1) - (l / 2 - 1)]) - (prefix[(i + (l / 2 - 1)) + 1] - prefix[i]);
                result = min(result, cnt2 + cnt1);
            }
        }
        return result;
    }
};
