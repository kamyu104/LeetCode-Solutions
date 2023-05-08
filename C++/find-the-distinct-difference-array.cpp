// Time:  O(n)
// Space: O(n)

// hash table, prefix sum
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> result(size(nums));
        unordered_set<int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            lookup.emplace(nums[i]);
            result[i] = size(lookup);
        }
        lookup.clear();
        for (int i = size(nums) - 1; i >= 0; --i) {
            result[i] -= size(lookup);
            lookup.emplace(nums[i]);
        }
        return result;
    }
};
