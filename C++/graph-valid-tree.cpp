
// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

class Solution {
public:
    struct node {
        int parent = -1;
        vector<int>neighbors;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        } else if (n == 1) {
            return true;
        }

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.emplace_back(edge.second);
            nodes[edge.second].neighbors.emplace_back(edge.first);
        }

        if (nodes.size() != n) {
            return false;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (const auto& n : nodes[i].neighbors) {
                if (n != nodes[i].parent) {
                    if (visited.find(n) != visited.end()) {
                        return false;
                    } else {
                        visited.emplace(n);
                        nodes[n].parent = i;
                        q.emplace(n);
                    }
                }
            }
        }
        return true;
    }
};
