// Time:  O(n + l)
// Space: O(h + l)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

// kmp solution
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        const auto& [pattern, prefix] = getPrefix(head);
        return dfs(pattern, prefix, root, -1);
    }

private:
    bool dfs(const vector<int>& pattern,
             const vector<int>& prefix,
             TreeNode *root, int j) {
        if (!root) {
            return false;
        }
        while (j + 1 && pattern[j + 1] != root->val) {
            j = prefix[j];
        }
        if (pattern[j + 1] == root->val) {
            ++j;
        }
        if (j + 1 == pattern.size()) {
            return true;
        }
        return dfs(pattern, prefix, root->left, j) ||
               dfs(pattern, prefix, root->right, j);
    }
    
    pair<vector<int>, vector<int>> getPrefix(ListNode *head) {
        vector<int> pattern = {head->val};
        vector<int> prefix = {-1};
        int j = -1;
        auto node = head->next;
        while (node) {
            while (j + 1 && pattern[j + 1] != node->val) {
                j = prefix[j];
            }
            if (pattern[j + 1] == node->val) {
                ++j;
            }
            pattern.emplace_back(node->val);
            prefix.emplace_back(j);
            node = node->next;
        }
        return {pattern, prefix};
    }
};

// Time:  O(n * min(h, l))
// Space: O(h)
// dfs solution
class Solution2 {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        return dfs(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }

private:
    bool dfs(ListNode *head, TreeNode *root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        return root->val == head->val &&
               (dfs(head->next, root->left) ||
                dfs(head->next, root->right));
    }
};
