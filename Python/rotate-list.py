# Time:  O(n)
# Space: O(1)
#
# Given a list, rotate the list to the right by k places, where k is non-negative.
# 
# For example:
# Given 1->2->3->4->5->NULL and k = 2,
# return 4->5->1->2->3->NULL.
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
    # @param k, an integer
    # @return a ListNode
    def rotateRight(self, head, k):
        if head is None:
            return head
        
        cur, len = head, 1
        while cur.next:
            cur = cur.next
            len += 1
        cur.next = head
        
        cur = head
        shift = len - k % len - 1 
        while shift > 0:
            cur = cur.next
            shift -= 1
        
        result = cur.next
        cur.next = None
        
        return result
    
if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution().rotateRight(head, 2)