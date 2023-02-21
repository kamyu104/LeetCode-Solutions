// Time:  O(logr)
// Space: O(1)

// hash table, bit manipulations
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        int base = 1;
        for (; lookup.count(base); base <<= 1);
        return base;
    }
};
