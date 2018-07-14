// Time:  O(n)
// Space: O(h)

/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        vector<Node*> stack{root};
        while (!stack.empty()) {
            auto node = stack.back(); stack.pop_back();
            result.emplace_back(node->val);
            for (auto rit = node->children.rbegin();
                 rit != node->children.rend();
                 ++rit) {
                if (*rit) {
                    stack.emplace_back(*rit);
                }
            }
        }
        return result;
    }
};
