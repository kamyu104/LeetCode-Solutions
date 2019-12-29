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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        Iterator<TreeNode*> left(root1), right(root2);
        while (*left || *right) {
            if (!*right || ((*left) && (*left)->val < (*right)->val)) {
                result.emplace_back((*left)->val);
                ++left;
            } else {
                result.emplace_back((*right)->val);
                ++right;
            }
        }
        return result;
    }

private:
    template<typename T>
    class Iterator {
    public:
        Iterator(T root)
         : stack_{{root, false}}
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
                stack_.emplace_back(root->right, false);
                stack_.emplace_back(root, true);
                stack_.emplace_back(root->left, false);
            }
            curr_ = T{};
            return *this;
        }
        
        const T& operator*() const {
            return curr_;
        }
        
    private:
        vector<pair<T, bool>> stack_;
        T curr_;
    };
};
