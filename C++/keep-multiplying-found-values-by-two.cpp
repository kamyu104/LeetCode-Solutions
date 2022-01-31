// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        for (; lookup.count(original); original *= 2);
        return original;
    }
};
