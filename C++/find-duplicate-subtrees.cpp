// Time:  O(n)
// Space: O(n)

class Solution {
private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= std::hash<A>{}(a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<B>{}(b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<C>{}(c) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, vector<TreeNode *>> trees;
        unordered_map<tuple<int, int, int>, int, TupleHash<int, int, int>> lookup;
        getid(root, &lookup, &trees);
        
        vector<TreeNode *> result;
        for (const auto& kvp : trees) {
            if (kvp.second.size() > 1) {
                result.emplace_back(kvp.second[0]);
            }
        }
        return result;
    }

private:
    int getid(TreeNode *root,
              unordered_map<tuple<int, int, int>, int, TupleHash<int, int, int>> *lookup,
              unordered_map<int, vector<TreeNode *>> *trees) {
        auto node_id = 0;
        if (root) {
            const auto& data = make_tuple(root->val,
                                          getid(root->left, lookup, trees),
                                          getid(root->right, lookup, trees));
            if (!lookup->count(data)) {
                (*lookup)[data] = lookup->size() + 1;
            }
            node_id = (*lookup)[data];
            (*trees)[node_id].emplace_back(root);
        }
        return node_id;
    }
};

// Time:  O(n * h)
// Space: O(n * h)
class Solution2 {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> lookup;
        vector<TreeNode*> result;
        postOrderTraversal(root, &lookup, &result);
        return result;
    }

private:
    string postOrderTraversal(TreeNode* node, unordered_map<string, int>* lookup, vector<TreeNode*> *result) {
        if (!node) {
            return "";
        }
        string s = "(";
        s += postOrderTraversal(node->left, lookup, result);
        s += to_string(node->val);
        s += postOrderTraversal(node->right, lookup, result);
        s += ")";
        if ((*lookup)[s] == 1) {
            result->emplace_back(node);
        }
        ++(*lookup)[s];
        return s;
    }
};
