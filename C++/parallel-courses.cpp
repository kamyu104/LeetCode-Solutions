// Time:  O(|V| + |E|)
// Space: O(|E|)

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> g;
        vector<int> in_degree(N);
        for (const auto& r : relations) {
            g[r[0] - 1].emplace_back(r[1] - 1);          
            ++in_degree[r[1] - 1];
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < N; ++i) {
            if (!in_degree[i]) {
                q.emplace(1, i);
            }
        }

        int result = 0;
        int count = N;
        while (!q.empty()) {
            int level, u;
            tie(level, u) = q.front(); q.pop();
            --count;
            result = level;
            for (const auto& v : g[u]) {
                --in_degree[v];
                if (!in_degree[v]) {
                    q.emplace(level+1, v);
                }
            }
        }
        return count == 0 ? result : -1;
    }
};
