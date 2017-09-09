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

namespace std{
    namespace
    {

        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     http://stackoverflow.com/questions/4948780

        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, std::get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, std::get<0>(tuple));
          }
        };
    }

    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              

    };
}

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, vector<TreeNode *>> trees;
        unordered_map<tuple<int, int, int>, int> lookup;
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
              unordered_map<tuple<int, int, int>, int> *lookup,
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
