// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N);
        for (const auto& dislike : dislikes) {
            int u = dislike[0] - 1, v = dislike[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        vector<int> color(N);
        color[0] = 1;
        queue<int> q({0});
        while (!q.empty()) {
            const auto cur = q.front(); q.pop();
            for (const auto& nei : adj[cur]) {
                if (color[nei] == color[cur]) {
                    return false;
                } else if (color[nei] == -color[cur]) {
                    continue;
                }
                color[nei] = -color[cur];
                q.emplace(nei);
            }
        }
        return true;
    }
};
