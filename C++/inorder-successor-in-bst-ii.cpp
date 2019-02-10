// Time:  O(h)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (node->right != nullptr) {
            node = node->right;
            while(node->left != nullptr) {
                node = node->left;
            }
            return node;
        }
        while (node->parent != nullptr &&
               node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};
