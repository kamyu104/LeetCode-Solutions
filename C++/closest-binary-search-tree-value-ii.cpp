// Time:  O(h + k)
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // The forward or backward iterator.
        const auto backward = [](const vector<TreeNode*>& s) { return s.back()->left; };
        const auto forward = [](const vector<TreeNode*>& s) { return s.back()->right; };
        const auto closest = [&target](const TreeNode* a, const TreeNode* b) { 
                                return abs(a->val - target) < abs(b->val - target); 
                            };

        // Build the stack to the closest node.
        vector<TreeNode*> s;
        while (root) {
            s.emplace_back(root);
            root = target < root->val ? root->left : root->right;
        }

        // Get the stack to the next smaller node.
        vector<TreeNode*> forward_stack(s.cbegin(), next(min_element(s.cbegin(), s.cend(), closest)));
        vector<TreeNode*> backward_stack(forward_stack);
        nextNode(backward_stack, backward, forward);
    
        // Get the closest k values by advancing the iterators of the stacks.
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (backward_stack.empty() ||
                (!forward_stack.empty() && closest(forward_stack.back(), backward_stack.back()))) {
                result.emplace_back(forward_stack.back()->val);
                nextNode(forward_stack, forward, backward);
            } else if (forward_stack.empty() ||
                       (!backward_stack.empty() && !closest(forward_stack.back(), backward_stack.back()))) {
                result.emplace_back(backward_stack.back()->val);
                nextNode(backward_stack, backward, forward);
            }
        }
        return result;
    }
    
    // Helper to make a stack to the next node.
    template<typename T, typename U>
    void nextNode(vector<TreeNode*>& s, const T& child1, const U& child2) {
        if (!s.empty()) {
            if (child2(s)) {
                s.emplace_back(child2(s));
                while (child1(s)) {
                    s.emplace_back(child1(s));
                }
            } else {
                auto child = s.back();
                s.pop_back();
                while (!s.empty() && child == child2(s)) {
                    child = s.back();
                    s.pop_back();
                }
            }
        }
    }
};
