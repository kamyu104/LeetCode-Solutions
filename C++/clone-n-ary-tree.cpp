// Time:  O(n)
// Space: O(h)

class Solution {
public:
    Node* cloneTree(Node* root) {
        using RET = Node*;
        RET result{};
        vector<tuple<int, RET, shared_ptr<RET>, RET *>> stk = {{1, root, nullptr, &result}};
        while (!stk.empty()) {
            const auto [step, node, ret1, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                *ret = new Node(node->val);
                for (int i = node->children.size() - 1; i >= 0; --i) {
                    const auto& ret1 = make_shared<RET>();
                    stk.emplace_back(2, nullptr, ret1, ret);
                    stk.emplace_back(1, node->children[i], nullptr, ret1.get());
                }
            } else {
                (*ret)->children.emplace_back(*ret1);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    Node* cloneTree(Node* root) {
        return dfs(root);
    }

private:
    Node *dfs(Node *node) {
        if (!node) {
            return nullptr;
        }
        auto copy = new Node(node->val);
        for (const auto& child : node->children) {
            copy->children.emplace_back(dfs(child));
        }
        return copy;
    }
};
