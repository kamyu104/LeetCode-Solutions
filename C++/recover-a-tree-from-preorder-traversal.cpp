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

// iterative stack solution
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        vector<TreeNode *> stack;
        while (i < S.length()) {
            int j = S.find_first_not_of("-", i);
            int level = j - i;
            i = j;
            while (stack.size() > level) {
                stack.pop_back();
            }
            j = S.find_first_of("-", i);
            auto node = new TreeNode(stoi(S.substr(i, j - i)));
            i = j;
            if (!stack.empty()) {
                if (!stack.back()->left) {
                    stack.back()->left = node;
                } else{
                    stack.back()->right = node;
                }
            }
            stack.emplace_back(node);
        }
        return stack.front();
    }
};

// Time:  O(n)
// Space: O(h)
// recursive solution
class Solution2 {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return recoverFromPreorderHelper(S, 0, &i);
    }

private:
    TreeNode* recoverFromPreorderHelper(const string& S, int level, int *i) {
        int j = S.find_first_not_of("-", *i);
        if (level != j - *i) {
            return nullptr;
        }
        *i = j;
        j = S.find_first_of("-", *i);
        auto node = new TreeNode(stoi(S.substr(*i, j - *i)));
        *i = j;
        node->left = recoverFromPreorderHelper(S, level + 1, i);
        node->right = recoverFromPreorderHelper(S, level + 1, i);
        return node;
    }
};
