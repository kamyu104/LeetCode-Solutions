// Time:  O(|V| + |E|)
// Space: O(|E|)

// Kahn’s algorithm (bfs solution)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in_degree;
        for (const auto& p : prerequisites) {
            ++in_degree[p[0]];
            adj[p[1]].emplace_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree.count(i)) {
                q.emplace(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            const auto node = q.front(); q.pop();
            result.emplace_back(node);
            for (const auto& i : adj[node]) {
                if (!--in_degree[i]) {
                    q.emplace(i);
                }
            }
        }
        return size(result) == numCourses;
    }
};

// Time:  O(|V| + |E|)
// Space: O(|E|)
// dfs solution
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in_degree;
        for (const auto& p : prerequisites) {
            ++in_degree[p[0]];
            adj[p[1]].emplace_back(p[0]);
        }
        vector<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree.count(i)) {
                stk.emplace_back(i);
            }
        }
        vector<int> result;
        while (!stk.empty()) {
            const auto node = stk.back(); stk.pop_back();
            result.emplace_back(node);
            for (const auto& i : adj[node]) {
                if (!--in_degree[i]) {
                    stk.emplace_back(i);
                }
            }
        }
        return size(result) == numCourses;
    }
};
