// Time:  O(k * h)
// Space: O(k + h)

// merge sort
class Solution {
public:
    int countGreatEnoughNodes(TreeNode* root, int k) {
        const auto& merge_at_most_k = [&](const auto& a, const auto& b) {
            vector<int> result;
            result.reserve(k);
            for (int i = 0, j = 0; i < size(a) || j < size(b);) {
                if (j == size(b) || (i < size(a) && a[i] < b[j])) {
                    result.emplace_back(a[i++]);
                } else {
                    result.emplace_back(b[j++]);
                }
                if (size(result) == k) {
                    break;
                }
            }
            return result;
        };
        
        int result = 0;
        const function<vector<int> (TreeNode *node)> merge_sort = [&](TreeNode *node) {
            if (!node) {
                return vector<int>{};
            }
            const auto& left = merge_sort(node->left), &right = merge_sort(node->right);
            auto smallest_k = merge_at_most_k(left, right);
            const auto& i = distance(cbegin(smallest_k), lower_bound(cbegin(smallest_k), cend(smallest_k), node->val));
            if (i == k) {
                ++result;
            } else {
                smallest_k.insert(begin(smallest_k) + i, node->val);
                if (size(smallest_k) == k + 1) {
                    smallest_k.pop_back();
                }
            }
            return smallest_k;
        };

        merge_sort(root);
        return result;
    }
};
