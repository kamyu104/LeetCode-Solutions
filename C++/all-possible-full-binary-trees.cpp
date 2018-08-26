// Time:  O(n * 4^n / n^(3/2)) ~= sum of Catalan numbers from 1 .. N
// Space: O(n * 4^n / n^(3/2)) ~= sum of Catalan numbers from 1 .. N

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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (!memo_.count(N)) {
            vector<TreeNode*> result;
            if (N == 1) {
                result.emplace_back(new TreeNode(0));
            } else if (N % 2 == 1) {
                for (int i = 0; i < N; ++i) {
                    for (const auto& left: allPossibleFBT(i)) {
                        for (const auto& right: allPossibleFBT(N - 1 - i)) {
                            auto node = new TreeNode(0);
                            node->left = left;
                            node->right = right;
                            result.emplace_back(node);
                        }
                    }
                }
            }
            memo_[N] = move(result);
        }
        return memo_[N];
    }

private:
    unordered_map<int, vector<TreeNode*>> memo_;
};
