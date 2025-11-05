// Time:  O(n + r)
// Space: O(r)

// hash table
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        vector<int> result;
        const auto& mn = ranges::min(nums);
        const auto& mx = ranges::max(nums);
        for (int x = mn + 1; x < mx; ++x) {
            if (!lookup.count(x)) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
