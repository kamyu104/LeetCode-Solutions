// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> result(N);
        vector<vector<int>> G(N);
        for (const auto& path : paths) {
            int x = path[0], y = path[1];
            G[x - 1].emplace_back(y - 1);
            G[y - 1].emplace_back(x - 1);
        }
        for (int i = 0; i < N; ++i) {
            unordered_set<int> candidates = {1, 2, 3, 4};
            for (const auto& j : G[i]) {
                candidates.erase(result[j]);
            }
            result[i] = *(candidates.cbegin());
        }
        return result;
    }
};
