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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        for (PreorderIterator<TreeNode*> left(original), right(cloned);
             *left && *right;
             ++left, ++right) {
            if ((*left) == target) {
                return (*right);
            }
        }
        return nullptr;
    }

private:
    template<typename T>
    class PreorderIterator {
    public:
        PreorderIterator(T root)
         : stack_{{root}}
         , curr_{} {
             ++(*this);
        }
        
        PreorderIterator& operator++() {
            while (!stack_.empty()) {
                const auto root = stack_.back(); stack_.pop_back();
                if (!root) {
                    continue;
                }
                stack_.emplace_back(root->right);
                stack_.emplace_back(root->left);
                curr_ = root;
                return *this;
            }
            curr_ = T{};
            return *this;
        }
        
        const T& operator*() const {
            return curr_;
        }
        
    private:
        vector<T> stack_;
        T curr_;
    };
};
