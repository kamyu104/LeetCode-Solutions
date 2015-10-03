// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

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

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.emplace_back(edge.second);
            nodes[edge.second].neighbors.emplace_back(edge.first);
        }
        for (int i = 0; i < n; ++i) {
            nodes[i].parent = -1;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            visited.insert(i);
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
