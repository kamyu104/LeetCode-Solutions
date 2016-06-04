// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 1;
        auto curr = head;
        for (; curr->next; curr = curr->next) {
            ++n;
        }
        curr->next = head;

        auto tail = curr;
        k = n - k % n;
        curr = head;
        for (int i = 0; i < k; curr = curr->next, ++i) {
            tail = curr;
        }

        tail->next = nullptr;
        return curr; 
    }
};
