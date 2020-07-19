// Time:  O(n)
// Space: O(h)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// one pass solution without recursion
class Solution {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        unordered_map<Node *, Node *> lookup;
        const auto& is_ancestor = iter_find_parents(root, nullptr, p, q, false, &lookup);
        if (lookup.count(p) && lookup[p] == q) {
            return root;
        }
        q->children.emplace_back(p);
        if (!is_ancestor) {
            lookup[p]->children.erase(find(begin(lookup[p]->children), end(lookup[p]->children), p));
        } else {
            lookup[q]->children.erase(find(begin(lookup[q]->children), end(lookup[q]->children), q));
            if (p == root) {
                root = q;
            } else {
                *find(begin(lookup[p]->children), end(lookup[p]->children), p) = q;
            }
        }
        return root;
    }

private:
    bool iter_find_parents(Node *node, Node *parent, Node *p, Node *q,
                           bool is_ancestor,
                           unordered_map<Node *, Node *> *lookup) {
        vector<tuple<int, Node *, Node *, bool, int>> stk = {tuple(1, node, parent, is_ancestor, -1)};
        while (!stk.empty()) {
            const auto [step, node, parent, is_ancestor, i] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (node == p || node == q) {
                    (*lookup)[node] = parent;
                    if (lookup->size() == 2) {
                        return is_ancestor;
                    }
                }
                stk.emplace_back(2, node, parent, is_ancestor, node->children.size() - 1);
            } else {
                if (i < 0) {
                    continue;
                }
                stk.emplace_back(2, node, parent, is_ancestor, i - 1);
                stk.emplace_back(1, node->children[i], node, is_ancestor || node == p, -1);
            }
        }
        assert(false);
        return false;
    }
};

// Time:  O(n)
// Space: O(h)
// one pass solution with recursion
class Solution_Recu {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        unordered_map<Node *, Node *> lookup;
        const auto& [_, is_ancestor] = find_parents(root, nullptr, p, q, false, &lookup);
        if (lookup.count(p) && lookup[p] == q) {
            return root;
        }
        q->children.emplace_back(p);
        if (!is_ancestor) {
            lookup[p]->children.erase(find(begin(lookup[p]->children), end(lookup[p]->children), p));
        } else {
            lookup[q]->children.erase(find(begin(lookup[q]->children), end(lookup[q]->children), q));
            if (p == root) {
                root = q;
            } else {
                *find(begin(lookup[p]->children), end(lookup[p]->children), p) = q;
            }
        }
        return root;
    }

private:
    pair<bool, bool> find_parents(Node *node, Node *parent, Node *p, Node *q,
                                  bool is_ancestor,
                                  unordered_map<Node *, Node *> *lookup) {
        if (node == p || node == q) {
            (*lookup)[node] = parent;
            if (lookup->size() == 2) {
                return {true, is_ancestor};
            }
        }
        for (const auto& child : node->children) {
            const auto& [found, result] = find_parents(child, node, p, q, is_ancestor || node == p, lookup);
            if (found) {
                return {true, result};
            }
        }
        return {false, false};
    }
};

// Time:  O(n)
// Space: O(h)
// two pass solution without recursion
class Solution2 {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        unordered_map<Node *, Node *> lookup;
        iter_find_parents(root, nullptr, p, q, &lookup);
        if (lookup.count(p) && lookup[p] == q) {
            return root;
        }
        q->children.emplace_back(p);
        if (!iter_is_ancestor(p, q)) {
            lookup[p]->children.erase(find(begin(lookup[p]->children), end(lookup[p]->children), p));
        } else {
            lookup[q]->children.erase(find(begin(lookup[q]->children), end(lookup[q]->children), q));
            if (p == root) {
                root = q;
            } else {
                *find(begin(lookup[p]->children), end(lookup[p]->children), p) = q;
            }
        }
        return root;
    }

private:
    void iter_find_parents(Node *node, Node *parent, Node *p, Node *q,
                           unordered_map<Node *, Node *> *lookup) {
        vector<tuple<int, Node *, Node *, int>> stk = {tuple(1, node, parent, -1)};
        while (!stk.empty()) {
            const auto [step, node, parent, i] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (node == p || node == q) {
                    (*lookup)[node] = parent;
                    if (lookup->size() == 2) {
                        return;
                    }
                }
                stk.emplace_back(2, node, parent, node->children.size() - 1);
            } else {
                if (i < 0) {
                    continue;
                }
                stk.emplace_back(2, node, parent, i - 1);
                stk.emplace_back(1, node->children[i], node, -1);
            }
        }
    }
    
    bool iter_is_ancestor(Node *node, Node *q) {
        vector<tuple<int, Node *, int>> stk = {tuple(1, node, -1)};
        while (!stk.empty()) {
            const auto [step, node, i] = stk.back(); stk.pop_back();
            if (step == 1) {
                stk.emplace_back(2, node, node->children.size() - 1);
            } else {
                if (i < 0) {
                    continue;
                }
                if (node->children[i] == q) {
                    return true;
                }
                stk.emplace_back(2, node, i - 1);
                stk.emplace_back(1, node->children[i], -1);
            }
        }
        return false;
    }
};

// Time:  O(n)
// Space: O(h)
// two pass solution with recursion
class Solution2_Recu {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        unordered_map<Node *, Node *> lookup;
        find_parents(root, nullptr, p, q, &lookup);
        if (lookup.count(p) && lookup[p] == q) {
            return root;
        }
        q->children.emplace_back(p);
        if (!is_ancestor(p, q)) {
            lookup[p]->children.erase(find(begin(lookup[p]->children), end(lookup[p]->children), p));
        } else {
            lookup[q]->children.erase(find(begin(lookup[q]->children), end(lookup[q]->children), q));
            if (p == root) {
                root = q;
            } else {
                *find(begin(lookup[p]->children), end(lookup[p]->children), p) = q;
            }
        }
        return root;
    }

private:
    bool find_parents(Node *node, Node *parent, Node *p, Node *q, unordered_map<Node *, Node *> *lookup) {
        if (node == p || node == q) {
            (*lookup)[node] = parent;
            if (lookup->size() == 2) {
                return true;
            }
        }
        for (const auto& child : node->children) {
            if (find_parents(child, node, p, q, lookup)) {
                return true;
            }
        }
        return false;
    }

    bool is_ancestor(Node *node, Node *q) {
        for (const auto& child : node->children) {
            if (child == q || is_ancestor(child, q)) {
                return true;
            }
        }
        return false;
    }
};
