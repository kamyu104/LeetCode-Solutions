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
class Solution {
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.empty() ? nullptr : str2treeHelper(s, &i);
    }

private:
    TreeNode* str2treeHelper(const string& s, int *i) {
        auto start = *i;
        if (s[*i] == '-') {
            ++(*i);
        }
        while (isdigit(s[*i])) {
            ++(*i);
        }
        
        auto node = new TreeNode(stoi(s.substr(start, *i - start)));
        if (s[*i] == '(') {
            ++(*i);
            node->left = str2treeHelper(s, i);
            ++(*i);
        }
        if (s[*i] == '(') {
            ++(*i);
            node->right = str2treeHelper(s, i);
            ++(*i);
        }
        return node;
    }
};
