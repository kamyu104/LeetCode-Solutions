// Time:  O((m + n) * log(m + n))
// Space: O(m + n)

// freq table, sort
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> cnt;
        for (const auto& x : items1) {
            cnt[x[0]] += x[1];
        }
        for (const auto& x : items2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> result;
        for (const auto& [k, v] : cnt) {
            result.push_back({k, v});
        }
        sort(begin(result), end(result));
        return result;
    }
};
