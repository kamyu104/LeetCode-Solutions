# Time:  O(n)
# Space: O(1)
#
# Given a singly linked list L: L0->L1->...->Ln-1->Ln,
# reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
# 
# You must do this in-place without altering the nodes' values.
# 
# For example,
# Given {1,2,3,4}, reorder it to {1,4,2,3}.
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
            
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))
        
class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        if head == None or head.next == None:
            return head
        
        fast, slow, prev = head, head, None
        while fast != None and fast.next != None:
            fast, slow, prev = fast.next.next, slow.next, slow
        current, prev.next, prev = slow, None, None
        
        while current != None:
            current.next, prev, current = prev, current, current.next
            
        l1, l2 = head, prev
        dummy = ListNode(0)
        current = dummy

        while l1 != None and l2 != None:
            current.next, current, l1 = l1, l1, l1.next
            current.next, current, l2 = l2, l2, l2.next
            
        return dummy.next

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution().reorderList(head)