// Time:  O(|V| + |E|)
// Space: O(|E|)

// dfs solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> in_degree, out_degree;
        for (const auto& p : prerequisites) {
            in_degree[p[0]].emplace(p[1]);
            out_degree[p[1]].emplace(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree.count(i)) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            const auto node = q.front(); q.pop();
            for (const auto& i : out_degree[node]) {
                in_degree[i].erase(node);
                if (in_degree[i].empty()) {
                    q.emplace(i);
                    in_degree.erase(i);
                }
            }
            out_degree.erase(node);
        }
        return in_degree.empty() && out_degree.empty();
    }
};

// Time:  O(|V| + |E|)
// Space: O(|E|)
// bfs solution
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> in_degree, out_degree;
        for (const auto& p : prerequisites) {
            in_degree[p[0]].emplace(p[1]);
            out_degree[p[1]].emplace(p[0]);
        }
        vector<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree.count(i)) {
                stk.emplace_back(i);
            }
        }
        while (!stk.empty()) {
            const auto node = stk.back(); stk.pop_back();
            for (const auto& i : out_degree[node]) {
                in_degree[i].erase(node);
                if (in_degree[i].empty()) {
                    stk.emplace_back(i);
                    in_degree.erase(i);
                }
            }
            out_degree.erase(node);
        }
        return in_degree.empty() && out_degree.empty();
    }
};
