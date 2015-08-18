// Time:  O(n)
// Space: O(n)

class Solution {
public:
    struct node {
        int parent;
        vector<int>neighbors;
    };
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int,node> nodes;
        unordered_set<int> visited;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.emplace_back(edge.second);
            nodes[edge.second].neighbors.emplace_back(edge.first);
        }
        for (int i = 0; i < n; ++i) {
            nodes[i].parent = -1;
        }

        queue<int> q;
        q.emplace(0);
        visited.insert(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (const auto& n : nodes[i].neighbors) {
                if (n != nodes[i].parent) {
                    if (visited.find(n) != visited.end()) {
                        return false;
                    } else {
                        visited.insert(n);
                        nodes[n].parent = i;
                        q.emplace(n);
                    }
                }
            }
        }
        return true;
    }
};
