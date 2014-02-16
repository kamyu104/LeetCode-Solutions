// Time Complexity: O(n)
// Space Complexity: O(1)

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
        void reorderList(ListNode *head) {
            if(!head) return;

            ListNode *slow = head;
            ListNode *fast = head;

            while(fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // split into two lists
            ListNode *tmp = slow->next;
            slow->next = nullptr;
            slow = tmp;

            merge(head, reverse(slow));
        }

    private:
        ListNode *reverse(ListNode *head) {
            ListNode dummy(INT_MIN);

            while(head) {
                ListNode *tmp = head->next;

                head->next = dummy.next; 
                dummy.next = head;

                head = tmp;
            }

            return dummy.next;
        }

        ListNode *merge(ListNode *list1, ListNode *list2) {
            ListNode dummy(INT_MIN);
            ListNode *ptr = &dummy;

            while(list1 && list2) {
                ListNode *tmp = list1->next; // backup list1 next

                ptr->next = list1;
                ptr = ptr->next;
                ptr->next = list2; // list1 next is overwritten
                ptr = ptr->next;

                list1 = tmp;
                list2 = list2->next;
            }

            if(list1) ptr->next = list1; // append remaining list1

            return dummy.next;
        }
};
