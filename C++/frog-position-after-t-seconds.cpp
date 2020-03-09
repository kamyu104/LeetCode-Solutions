// Time:  O(n)
// Space: O(n)

// bfs solution with better precision
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[1] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        
        vector<tuple<int, int, int, int>> stk = {{t, 1, 0, 1}};
        while (!stk.empty()) {
            vector<tuple<int, int, int, int>> new_stk;
            while (!stk.empty()) {
                const auto [t, node, parent, choices] = stk.back(); stk.pop_back();
                if (!t || !(G.at(node).size() - int(parent != 0))) {
                    if (node == target) {
                        return 1.0 / choices;
                    }
                    continue;
                }
                for (const auto& child : G.at(node)) {
                    if (child == parent) {
                        continue;
                    }
                    new_stk.emplace_back(t - 1, child, node,
                                         choices * (G.at(node).size() - int(parent != 0)));
                }
            }
            stk = move(new_stk);
        }
        return 0.0;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs solution with stack with better precision
class Solution2 {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[1] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        
        vector<tuple<int, int, int, int>> stk = {{t, 1, 0, 1}};
        while (!stk.empty()) {
            const auto [t, node, parent, choices] = stk.back(); stk.pop_back();
            if (!t || !(G.at(node).size() - int(parent != 0))) {
                if (node == target) {
                    return 1.0 / choices;
                }
                continue;
            }
            for (const auto& child : G.at(node)) {
                if (child == parent) {
                    continue;
                }
                stk.emplace_back(t - 1, child, node,
                                 choices * (G.at(node).size() - int(parent != 0)));
            }
        }
        return 0.0;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs solution with recursion with better precision
class Solution3 {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[1] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        int choices = dfs(G, target, t, 1, 0);
        return choices ? 1.0 / choices : 0.0;
    }

private:
    int dfs(const unordered_map<int, vector<int>>& G,
               int target, int t, int node, int parent) {
        if (!t || !(G.at(node).size() - int(parent != 0))) {
            return (node == target);
        }
        int result = 0;
        for (const auto& child : G.at(node)) {
            if (child == parent) {
                continue;
            }
            if (result = dfs(G, target, t - 1, child, node)) {
                break;
            }
        }
        return result * (G.at(node).size() - int(parent != 0));
    }
};

// Time:  O(n)
// Space: O(n)
// dfs solution with recursion
class Solution4 {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[1] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        return dfs(G, target, t, 1, 0);
    }

private:
    double dfs(const unordered_map<int, vector<int>>& G,
               int target, int t, int node, int parent) {
        if (!t || !(G.at(node).size() - int(parent != 0))) {
            return (node == target);
        }
        double result = 0.0;
        for (const auto& child : G.at(node)) {
            if (child == parent) {
                continue;
            }
            if (result = dfs(G, target, t - 1, child, node)) {
                break;
            }
        }
        return result / (G.at(node).size() - int(parent != 0));
    }
};
