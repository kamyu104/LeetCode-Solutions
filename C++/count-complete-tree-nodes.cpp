// Time:  O(h * h) = O((logn)^2)
// Space: O(1)

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
    int countNodes(TreeNode* root) {
        int count = 0, h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                count += 1 << h;
                root = root->right;
            } else {
                count += 1 << (h - 1);
                root = root->left;
            }
            --h;
        }
        return count;
    }

private:
    int height(TreeNode *root) {
        int h = -1;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }
};

// Time:  O(h * logn) = O((logn)^2)
// Space: O(1)
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        TreeNode *node = root;
        int level = 0;
        while (node->left != nullptr) {
            node = node->left;
            ++level;
        }
        int left = pow(2, level), right = pow(2, level + 1) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!check(root, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;  // find the the first node from right exists
    }

private:
    // Check if the nth node exist.
    bool check(TreeNode *root, int n) {
        //       1(1)
        //     /      \
        //   2(0)     3(1)   ↑
        //  /  \      /      d
        // 4(0) 5(1) 6(0)    ↓
        int base = 1;
        while (base <= n) {
            base <<= 1;
        }
        base >>= 2;  // base = 2^d
        TreeNode *node = root;
        while (base) {
            if ((n & base) == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            base >>= 1;
        }
        return node != nullptr;
    }
};
