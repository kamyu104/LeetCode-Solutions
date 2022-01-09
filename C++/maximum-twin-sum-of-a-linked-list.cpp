// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode dummy(0, head);
        auto slow = dummy.next, fast = dummy.next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        int result = 0;
        auto head2 = reverseList(slow);
        while (head) {
            result = max(result, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return result;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy;
        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }
};
