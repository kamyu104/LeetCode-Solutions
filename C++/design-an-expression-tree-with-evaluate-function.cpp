// Time:  O(n)
// Space: O(h)

#define ITER

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
};

class NodeIter : public Node {
public:
    NodeIter (int val) : val(val) {};
    NodeIter (char op, NodeIter *left, NodeIter *right) : op(op), left(left), right(right) {};
    virtual ~NodeIter () {};
    virtual int evaluate() const {
        int result = 0;
        vector<tuple<int, NodeIter *, unique_ptr<int>, unique_ptr<int>, int*>> stk;
        stk.emplace_back(1, const_cast<NodeIter *>(this), nullptr, nullptr, &result);
        while (!empty(stk)) {
            const auto [step, node, ret1, ret2, ret] = move(stk.back()); stk.pop_back();
            if (step == 1) {
                if (node->op == 0) {
                    *ret = node->val;
                    continue;
                }
                auto ret1 = make_unique<int>(), ret2 = make_unique<int>();
                auto p1 = ret1.get(), p2 = ret2.get();
                stk.emplace_back(2, node, move(ret1), move(ret2), ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, p2);
                stk.emplace_back(1, node->left, nullptr, nullptr, p1);
            } else if (step == 2) {
                int l = *ret1, r = *ret2;
                *ret = (node->op == '+') ? l + r :
                       (node->op == '-') ? l - r :
                       (node->op == '*') ? l * r :
                       (node->op == '/') ? l / r : 0;
            }
        }
        return result;
    }
    
public:
    int val;
    char op = 0;
    NodeIter *left = nullptr;
    NodeIter *right = nullptr;
};

class NodeRecu : public Node {
public:
    NodeRecu (int val) : val(val) {};
    NodeRecu (char op, NodeRecu *left, NodeRecu *right) : op(op), left(left), right(right) {};
    virtual ~NodeRecu () {};
    virtual int evaluate() const {
        if (op == 0) {
            return val;
        }
        int l = left->evaluate(), r = right->evaluate();
        return (op == '+') ? l + r :
               (op == '-') ? l - r :
               (op == '*') ? l * r :
               (op == '/') ? l / r : 0;
    }
    
public:
    int val;
    char op = 0;
    NodeRecu *left = nullptr;
    NodeRecu *right = nullptr;
};

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
#ifdef ITER
    using TreeNode = NodeIter;
#else
    using TreeNode = NodeRecu;
#endif
        vector<Node *> stk;
        for (const auto& s : postfix) {
            if (isdigit(s[0])) {
                stk.emplace_back(new TreeNode(stoi(s)));
            } else {
                auto right = dynamic_cast<TreeNode*>(stk.back()); stk.pop_back();
                auto left = dynamic_cast<TreeNode*>(stk.back()); stk.pop_back();
                stk.emplace_back(new TreeNode(s[0], left, right));
            } 
        }
        return stk.back();
    }
};
