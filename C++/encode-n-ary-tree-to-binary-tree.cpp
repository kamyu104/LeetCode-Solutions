// Time:  O(n)
// Space: O(h)

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto node = new TreeNode(root->val);
        if (!root->children.empty()) {
            node->right = encodeHelper(root->children[0], root, 0);
        }
        return node;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node*> children;
        auto node = new Node(root->val, children);
        decodeHelper(root->right, node);
        return node;
    }
    
private:
    TreeNode *encodeHelper(Node *root, Node *parent, int index) {
        if (root == nullptr) {
            return nullptr;
        }
        auto node = new TreeNode(root->val);
        if (index + 1 < parent->children.size()) {
            node->left = encodeHelper(parent->children[index + 1], parent, index + 1);
        }
        if (!root->children.empty()) {
            node->right = encodeHelper(root->children[0], root, 0);
        }
        return node;
    }
    
    void decodeHelper(TreeNode* root, Node* parent) {
        if (!root) {
            return;   
        }
        vector<Node*> children;
        auto node = new Node(root->val, children);
        decodeHelper(root->right, node);
        parent->children.push_back(node);
        decodeHelper(root->left, parent);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
