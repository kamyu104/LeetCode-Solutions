// Time:  O(n)
// Space: O(n)

// hash table, unordered set
class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int, unordered_set<int>> lookup;
        for (const auto& x : students) {
            lookup[x[1]].emplace(x[0]);
        }
        int result = 0;
        for (const auto& [_, v] : lookup) {
            result = max(result, static_cast<int>(size(v)));
        }
        return result;
    }
};
