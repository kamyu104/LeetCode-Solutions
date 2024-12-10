// Time:  O(n)
// Space: O(n)

// hash table, constructive algorithms
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int mn = ranges::min(nums);
        return mn >= k ? size(unordered_set<int>(cbegin(nums), cend(nums))) - (mn == k ? 1 : 0) : -1;
    }
};
