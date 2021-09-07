// Time:  O(n)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            auto node = new Node(insertVal, nullptr);
            node->next = node;
            return node;
        }
        auto curr = head;
        while (true) {
            if (curr->val < curr->next->val) {
                if (curr->val <= insertVal &&
                    insertVal <= curr->next->val) {
                    insertAfter(curr, insertVal);
                    break;
                }
            } else if (curr->val > curr->next->val) {
                if (curr->val <= insertVal ||
                    insertVal <= curr->next->val) {
                    insertAfter(curr, insertVal);
                    break;
                }
            } else {
                if (curr->next == head) {
                    insertAfter(curr, insertVal);
                    break;
                }
            }
            curr = curr->next;
        }
        return head; 
    }

private:
    void insertAfter(Node *node, int val) {
        node->next = new Node(val, node->next);
    }
};
