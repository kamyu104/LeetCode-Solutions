# Time:  O(n)
# Space: O(1)
#
# Reverse a linked list from position m to n. Do it in-place and in one-pass.
# 
# For example:
# Given 1->2->3->4->5->NULL, m = 2 and n = 4,
# 
# return 1->4->3->2->5->NULL.
# 
# Note:
# Given m, n satisfy the following condition:
# 1 <= m <= n <= length of list.
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
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
        diff, dummy, cur = n - m + 1, ListNode(-1), head
        dummy.next = head
        
        last_unswapped = dummy
        while cur and m > 1:
            cur, last_unswapped, m = cur.next, cur, m - 1
            
        prev, first_swapped = last_unswapped,  cur
        while cur and diff > 0:
            cur.next, prev, cur, diff = prev, cur, cur.next, diff - 1
            
        last_unswapped.next, first_swapped.next = prev, cur
        
        return dummy.next

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution().reverseBetween(head, 2, 4)
            