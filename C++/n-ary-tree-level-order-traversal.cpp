// Time:  O(n)
// Space: O(w)

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> result;
        vector<Node*> q{root};
        while (!q.empty()) {
            vector<int> curr;
            vector<Node*> next_q;
            for (const auto& node : q) {
                for (const auto& child : node->children) {
                    if (child) {
                        next_q.emplace_back(child);
                    }
                }
                curr.emplace_back(node->val);
            }
            result.emplace_back(move(curr));
            q = move(next_q);
        }
        return result;
    }
};
