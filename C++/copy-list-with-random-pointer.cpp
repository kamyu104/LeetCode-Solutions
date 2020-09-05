// Time:  O(n)
// Space: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Insert the copied node after the original one.
        for (auto *curr = head; curr; curr = curr->next->next) {
            auto *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
        }

        // Update random node.
        for (auto *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        // Seperate the copied nodes from original ones.
        Node dummy(0);
        for (auto *curr = head, *copy_curr = &dummy;
             curr;
             copy_curr = copy_curr->next, curr = curr->next) {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
        }

        return dummy.next;
    }
};
