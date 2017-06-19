// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> lookup;
        auto result = 0;
        for (const auto& num : nums) {
            ++lookup[num];
            for (const auto& diff : {-1, 1}) {
                if (lookup.count(num + diff)) {
                    result = max(result, lookup[num] + lookup[num + diff]);
                }
            }
        }
        return result;
    }
};
