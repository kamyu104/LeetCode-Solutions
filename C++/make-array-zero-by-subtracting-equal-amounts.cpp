// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            if (x) {
                lookup.emplace(x);
            }
        }
        return size(lookup);
    }
};
