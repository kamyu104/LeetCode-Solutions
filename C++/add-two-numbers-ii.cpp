// Time:  O(m + n)
// Space: O(m + n)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        while (l1) {
            stk1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.emplace(l2->val);
            l2 = l2->next;
        }

        ListNode *prev = nullptr, *head = nullptr;
        int sum = 0;
        while (!stk1.empty() || !stk2.empty()) {
            sum /= 10;
            if (!stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }
            
            if (!stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }
            
            head = new ListNode(sum % 10);
            head->next = prev;
            prev = head;
        }

        if (sum >= 10) {
            head = new ListNode(sum / 10);
            head->next = prev;
        }
        
        return head;
    }
};
