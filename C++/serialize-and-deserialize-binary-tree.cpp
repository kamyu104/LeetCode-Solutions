// Time:  O(n)
// Space: O(h)

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(const TreeNode *root, ostringstream& out) {
        if (!root)  {
            out << "# ";
        } else {
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
    }

    TreeNode *deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(in);
            root->right = deserializeHelper(in);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
