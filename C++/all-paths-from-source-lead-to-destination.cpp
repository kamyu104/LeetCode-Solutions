// Time:  O(n + e)
// Space: O(n + e)

class Solution {
public:
    enum Status { UNVISITED, VISITING, DONE };
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> children;
        for (const auto& edge : edges) {
            children[edge[0]].emplace_back(edge[1]);
        }
        vector<Status> status(n);
        return dfs(children, source, destination, &status);
    }

private:
    bool dfs(const unordered_map<int, vector<int>>& children,
             int node,
             int destination,
             vector<Status> *status) {

        if ((*status)[node] == DONE) {
            return true;
        }
        if ((*status)[node] == VISITING) {
            return false;
        }
        (*status)[node] = VISITING;
        if (!children.count(node) && node != destination) {
            return false;
        }
        if (children.count(node)) {
            for (const auto& child : children.at(node)) {
                if (!dfs(children, child, destination, status)) {
                    return false;
                }
            }
        }
        (*status)[node] = DONE;
        return true;
    }
};
