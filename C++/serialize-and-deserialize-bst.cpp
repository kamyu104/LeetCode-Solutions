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
        string data;
        serializeHelper(root, &data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializeHelper(numeric_limits<int>::min(), numeric_limits<int>::max(), data, &i);
    }


private:
    void serializeHelper(TreeNode *node, string *data) {
        if (node) {
            *data += to_string(node->val) + " ";
            serializeHelper(node->left, data);
            serializeHelper(node->right, data);
        }
    }

    TreeNode* deserializeHelper(int minVal, int maxVal, const string& data, int *i) {
        if (*i == data.length()) {
            return nullptr;
        }
        int j = data.find(' ', *i);
        auto val = stoi(data.substr(*i, j - *i));
        if (minVal < val && val < maxVal) {
            auto node = new TreeNode(val);
            *i = j + 1;
            node->left = deserializeHelper(minVal, val, data, i);
            node->right = deserializeHelper(val, maxVal, data, i);
            return node;
        } else {
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
