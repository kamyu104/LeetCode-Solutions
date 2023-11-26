// Time:  O(nlogn)
// Space: O(n)

// sort
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] < nums[b];
        });
        vector<vector<int>> groups;
        for (int i = 0; i < size(nums); ++i) {
            if (i - 1 < 0 || nums[idxs[i]] - nums[idxs[i - 1]] > limit) {
                groups.emplace_back();
            }
            groups.back().emplace_back(idxs[i]);
        }
        vector<int> result(size(nums), -1);
        for (const auto& g : groups) {
            vector<int> sorted_g(g);
            sort(begin(sorted_g), end(sorted_g));
            for (int i = 0; i < size(g); ++i) {
                result[sorted_g[i]] = nums[g[i]];
            }
        }
        return result;
    }
};
