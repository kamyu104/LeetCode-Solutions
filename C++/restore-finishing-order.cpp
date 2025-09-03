// Time:  O(n + min(8, n))
// Space: O(min(8, n))

// hash table
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> lookup(cbegin(friends), cend(friends));
        vector<int> result;
        for (const auto& x : order) {
            if (lookup.count(x)) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
