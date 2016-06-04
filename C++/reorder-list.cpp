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
class Solution {
    public:
        void reorderList(ListNode *head) {
        if (!head) {
            return;
        }

        auto slow = head, fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists.
        auto tmp = slow->next;
        slow->next = nullptr;
        slow = tmp;

        merge(head, reverse(slow));
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy{0};

        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode dummy{0};
        auto ptr = &dummy;

        while (list1 && list2) {
            auto tmp = list1->next;

            ptr->next = list1;
            ptr = ptr->next;
            ptr->next = list2;
            ptr = ptr->next;

            list1 = tmp;
            list2 = list2->next;
        }

        if (list1) {
            ptr->next = list1;
        }

        return dummy.next;
    }
};
