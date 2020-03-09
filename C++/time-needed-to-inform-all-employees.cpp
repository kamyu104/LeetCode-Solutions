// Time:  O(n)
// Space: O(n)

// dfs solution with stack
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                children[manager[i]].emplace_back(i);
            }
        }
 
        int result = 0;
        vector<pair<int, int>> stk = {{headID, 0}};
        while (!stk.empty()) {
            auto [node, curr] = stk.back(); stk.pop_back();
            curr += informTime[node];
            result = max(result, curr);
            if (!children.count(node)) {
                continue;
            }
            for (const auto& child : children.at(node)) {
                stk.emplace_back(child, curr);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs solution with recursion
class Solution2 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                children[manager[i]].emplace_back(i);
            }
        }
        return dfs(informTime, children, headID);
    }

private:
    int dfs(const vector<int>& informTime,
            const unordered_map<int, vector<int>>& children,
            int node) {
        if (!children.count(node)) {
            return informTime[node];
        }
        int result = 0;
        for (const auto& child : children.at(node)) {
            result = max(result, dfs(informTime, children, child));
        }
        return result + informTime[node];
    }
};
