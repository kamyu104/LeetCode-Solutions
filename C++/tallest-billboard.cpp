// Time:  O(n * 3^(n/2))
// Space: O(3^(n/2))

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        auto left = dp(rods.cbegin(), rods.cbegin() + rods.size() / 2);
        auto right = dp(rods.cbegin() + rods.size() / 2, rods.cend());
        int result = 0;
        for (const auto& kvp : left) {
            if (right.count(kvp.first)) {
                result = max(result,
                             left[kvp.first] + right[kvp.first] + kvp.first);
            }
        }
        return result;
    }
                              
private:
    unordered_map<int, int> dp(vector<int>::const_iterator it,
                               vector<int>::const_iterator end) {
        unordered_map<int, int> lookup;
        lookup[0] = 0;
        for (; it != end; ++it) {
            unordered_map<int, int> tmp(lookup);
            for (const auto& kvp : tmp) {
                lookup[kvp.first + *it] = max(lookup[kvp.first + *it], kvp.second);
                lookup[abs(kvp.first - *it)] = max(lookup[abs(kvp.first - *it)],
                                                   kvp.second + min(kvp.first, *it));
            }
        }
        return lookup;
    }
};
