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
        string output;
        serializeHelper(root, &output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        int start = 0;
        deserializeHelper(data, &start, &root);
        return root;
    }

private:
    bool getNumber(const string &data, int *start, int *num) {
        int sign = 1;
        if (data[*start] == '#') {
            *start += 2;  // Skip "# ".
            return false;
        } else if (data[*start] == '-') {
            sign = -1;
            ++(*start);
        }

        for (*num = 0; isdigit(data[*start]); ++(*start)) {
            *num = *num * 10 + data[*start] - '0';
        }
        *num *= sign;
        ++(*start);  // Skip " ".

        return true;
    }
    
    void serializeHelper(const TreeNode *root, string *prev) {
        if (!root)  {
            prev->append("# ");
        } else {
            prev->append(to_string(root->val).append(" "));
            serializeHelper(root->left, prev);
            serializeHelper(root->right, prev);
        }
    }

    void deserializeHelper(const string& data,
                           int *start,  TreeNode **root) {
        int num;
        if (!getNumber(data, start, &num)) {
            *root = nullptr;
        } else {
            *root = new TreeNode(num);
            deserializeHelper(data, start, &((*root)->left));
            deserializeHelper(data, start, &((*root)->right));
        }
    }
};


// Time:  O(n)
// Space: O(n)
class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);  // Space: O(n)
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
