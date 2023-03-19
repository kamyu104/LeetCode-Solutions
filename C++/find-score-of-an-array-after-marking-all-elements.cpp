// Time:  O(nlogn)
// Space: O(n)

// simulation, sort, hash table
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
        });
        vector<bool> lookup(size(nums));
        int64_t result = 0;
        for (const auto& i : idxs) {
            if (lookup[i]) {
                continue;
            }
            lookup[i] = true;
            if (i - 1 >= 0) {
                lookup[i - 1] = true;
            }
            if (i + 1 < size(lookup)) {
                lookup[i + 1] = true;
            }
            result += nums[i];
        }
        return result;
    }
};
