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
        ListNode *cur = head;
        for (; cur->next; cur = cur->next) {
            ++n;
        }
        cur->next = head;

        ListNode *tail = cur;
        k = n - k % n;
        cur = head;
        for (int i = 0; i < k; cur = cur->next, ++i) {
            tail = cur;
        }

        tail->next = nullptr;
        return cur; 
    }
};
