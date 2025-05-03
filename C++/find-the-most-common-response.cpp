// Time:  O(n * l)
// Space: O(n * l)

// hash table, freq table
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> cnt;
        for (const auto& r : responses) {
            for (const auto& x : unordered_set<string>(cbegin(r), cend(r))) {
                ++cnt[x];
            }
        }
        pair<int, string> result = {numeric_limits<int>::max(), ""};
        for (const auto& [x, c] : cnt) {
            result = min(result, pair(-c, x));
        }
        return result.second;
    }
};
