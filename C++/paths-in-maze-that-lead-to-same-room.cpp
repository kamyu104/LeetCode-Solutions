// Time:  O(|V|^3)
// Space: O(|E|)

class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<unordered_set<int>> adj(n);
        for (const auto& x : corridors) {
            adj[min(x[0], x[1]) - 1].emplace(max(x[0], x[1]) - 1);
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (const auto& j : adj[i]) {
                for (const auto& k : adj[j]) {
                    result += adj[i].count(k);
                }
            }
        }
        return result;
    }
};
