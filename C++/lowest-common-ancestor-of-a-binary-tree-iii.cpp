// Time:  O(h)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto a = p, b = q;
        while (a != b) {
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }
        return a;
    }
};

// Time:  O(h)
// Space: O(1)
class Solution2 {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int p_d = depth(p);
        int q_d = depth(q);
        while (p_d > q_d) {
            p = p->parent;
            --p_d;
        }
        while (p_d < q_d) {
            q = q->parent;
            --q_d;
        }
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }

private:
    int depth(Node *node) {
        int d = 0;
        while (node) {
            node = node->parent;
            ++d;
        }
        return d;
    }
};
