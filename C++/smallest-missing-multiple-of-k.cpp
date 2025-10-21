// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        for (int i = 1; i <= size(lookup); ++i) {
            if (!lookup.count(i * k)) {
                return i * k;
            }
        }
        return (size(lookup) + 1) * k;
    }
};
