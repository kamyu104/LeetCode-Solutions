
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *tail=new ListNode;
        ListNode *head=tail;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                tail->next= new ListNode(l1->val);
                l1=l1->next;
            }
            else
            {
                 tail->next= new ListNode(l2->val);
                 l2=l2->next;
            }
            tail=tail->next;
        }
        while(l1!=nullptr)
        {
            tail->next= new ListNode(l1->val);
                l1=l1->next;
            tail=tail->next;
        }
        while(l2!=nullptr)
        {
           tail->next= new ListNode(l2->val);
             l2=l2->next;
            tail=tail->next;
        }
        head=head->next;
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};
