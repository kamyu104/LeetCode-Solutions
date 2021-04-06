// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> lookup;
        for (const auto& log : logs) {
            lookup[log[0]].emplace(log[1]);
        }
        vector<int> result(k);
        for (const auto& [_, ts] : lookup) {
            ++result[size(ts) - 1];
        }
        return result;
    }
};
