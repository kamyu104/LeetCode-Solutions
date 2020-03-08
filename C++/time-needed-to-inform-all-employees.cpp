// Time:  O(n)
// Space: O(n)

class Solution {
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
