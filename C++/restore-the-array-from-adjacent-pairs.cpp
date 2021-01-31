// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].emplace_back(pair[1]);
            adj[pair[1]].emplace_back(pair[0]);
        }
        vector<int> result;
        for (const auto& [first, neighbors] : adj) {
            if (size(neighbors) == 1) {
                result.emplace_back(first);
                result.emplace_back(neighbors.front());
                break;
            }
        }
        while (size(result) != size(adjacentPairs) + 1) {
            result.emplace_back(adj[result.back()][adj[result.back()][0] == result[size(result) - 2]]);
        }
        return result;
    }
};
