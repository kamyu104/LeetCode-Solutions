# Time:  O(n)
# Space: O(1)
#
# Given a linked list, remove the nth node from the end of list and return its head.
# 
# For example,
# 
#    Given linked list: 1->2->3->4->5, and n = 2.
# 
#    After removing the second node from the end, the linked list becomes 1->2->3->5.
# Note:
# Given n will always be valid.
# Try to do this in one pass.
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        if self is None:
            return "Nil"
        else:
            return "{} -> {}".format(self.val, repr(self.next))
        
class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(-1)
        dummy.next = head
        slow, fast = dummy, dummy
        
        for i in xrange(n):
            fast = fast.next
            
        while fast.next:
            slow, fast = slow.next, fast.next
            
        slow.next = slow.next.next
        
        return dummy.next

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    
    print Solution().removeNthFromEnd(head, 2)