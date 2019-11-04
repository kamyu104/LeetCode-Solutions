// Time:  O(n)
// Space: O(n)

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        Iterator<TreeNode*> left(root1, true), right(root2, false);
        while (*left && *right) {
            if ((*left)->val + (*right)->val < target) {
                ++left;
            } else if ((*left)->val + (*right)->val > target) {
                ++right;
            } else {
                return true;
            }
        }
        return false;
    }

private:
    template<typename T>
    class Iterator {
    public:
        Iterator(T root, bool asc)
         : stack_{{root, false}}
         , asc_{asc}
         , curr_{} {
             ++(*this);
        }
        
        Iterator& operator++() {
            while (!stack_.empty()) {
                T root; bool is_visited;
                tie(root, is_visited) = stack_.back(); stack_.pop_back();
                if (!root) {
                    continue;
                }
                if (is_visited) {
                    curr_ = root;
                    return *this;
                }
                if (asc_) {
                    stack_.emplace_back(root->right, false);
                    stack_.emplace_back(root, true);
                    stack_.emplace_back(root->left, false);
                } else {
                    stack_.emplace_back(root->left, false);
                    stack_.emplace_back(root, true);
                    stack_.emplace_back(root->right, false);
                }
            }
            curr_ = T{};
            return *this;
        }
        
        const T& operator*() const {
            return curr_;
        }
        
    private:
        vector<pair<T, bool>> stack_;
        bool asc_;
        T curr_;
    };
};
