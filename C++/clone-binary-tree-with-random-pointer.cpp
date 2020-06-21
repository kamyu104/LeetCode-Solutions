// Time:  O(n)
// Space: O(h)

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {    
        const auto& merge = [](Node *node) {
            auto copy = new NodeCopy(node->val);
            tie(node->left, copy->left) = pair(reinterpret_cast<Node*>(copy), 
                                               reinterpret_cast<NodeCopy*>(node->left));
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& clone = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            node->left->random = node->random ? node->random->left : nullptr;
            node->left->right = node->right ? node->right->left : nullptr;
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& split = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            tie(node->left, copy->left) = pair(copy->left ? reinterpret_cast<Node*>(copy->left) : nullptr,
                                               copy->left ? copy->left->left : nullptr);
            return pair{reinterpret_cast<Node*>(node->left), copy};
        };
        iter_dfs(root, merge);
        iter_dfs(root, clone);
        return iter_dfs(root, split);
    }

private:
    NodeCopy *iter_dfs(Node *root, const function<pair<Node*, NodeCopy*>(Node*)>& callback) {
        NodeCopy *result = nullptr;
        vector<Node *> stk = {root};
        while (!stk.empty()) {
            auto node = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            const auto& [left_node, copy] = callback(node);
            if (!result) {
                result = copy;
            }
            stk.emplace_back(node->right);
            stk.emplace_back(left_node);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution_Recu {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {    
        const auto& merge = [](Node *node) {
            auto copy = new NodeCopy(node->val);
            tie(node->left, copy->left) = pair(reinterpret_cast<Node*>(copy), 
                                               reinterpret_cast<NodeCopy*>(node->left));
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& clone = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            node->left->random = node->random ? node->random->left : nullptr;
            node->left->right = node->right ? node->right->left : nullptr;
            return pair{reinterpret_cast<Node*>(copy->left), copy};
        };
        const auto& split = [](Node *node) {
            auto copy = reinterpret_cast<NodeCopy*>(node->left);
            tie(node->left, copy->left) = pair(copy->left ? reinterpret_cast<Node*>(copy->left) : nullptr,
                                               copy->left ? copy->left->left : nullptr);
            return pair{reinterpret_cast<Node*>(node->left), copy};
        };
        dfs(root, merge);
        dfs(root, clone);
        return dfs(root, split);
    }

private:
    NodeCopy *dfs(Node *node, const function<pair<Node*, NodeCopy*>(Node*)>& callback) {
        if (!node) {
            return nullptr;
        }
        const auto& [left_node, copy] = callback(node);
        dfs(left_node, callback);
        dfs(node->right, callback);
        return copy;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> lookup;
        lookup[nullptr] = nullptr;
        vector<Node *> stk = {root};
        while (!stk.empty()) {
            auto node = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            if (!lookup.count(node)) {
                lookup[node] = new NodeCopy(); 
            }
            if (!lookup.count(node->left)) {
                lookup[node->left] = new NodeCopy(); 
            }
            if (!lookup.count(node->right)) {
                lookup[node->right] = new NodeCopy(); 
            }
            if (!lookup.count(node->random)) {
                lookup[node->random] = new NodeCopy(); 
            }
            lookup[node]->val = node->val;
            lookup[node]->left = lookup[node->left];
            lookup[node]->right = lookup[node->right];
            lookup[node]->random = lookup[node->random];
            stk.emplace_back(node->right);
            stk.emplace_back(node->left);
        }
        return lookup[root];
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2_Recu {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> lookup;
        lookup[nullptr] = nullptr;
        dfs(root, &lookup);
        return lookup[root];
    }

private:
    void dfs(Node *node, unordered_map<Node*, NodeCopy*> *lookup) {
        if (!node) {
            return;
        }
        if (!lookup->count(node)) {
            (*lookup)[node] = new NodeCopy(); 
        }
        if (!lookup->count(node->left)) {
            (*lookup)[node->left] = new NodeCopy(); 
        }
        if (!lookup->count(node->right)) {
            (*lookup)[node->right] = new NodeCopy(); 
        }
        if (!lookup->count(node->random)) {
            (*lookup)[node->random] = new NodeCopy(); 
        }
        (*lookup)[node]->val = node->val;
        (*lookup)[node]->left = (*lookup)[node->left];
        (*lookup)[node]->right = (*lookup)[node->right];
        (*lookup)[node]->random = (*lookup)[node->random];
        dfs(node->left, lookup);
        dfs(node->right, lookup);
    }
};
