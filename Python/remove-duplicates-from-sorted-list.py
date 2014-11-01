# Time:  O(n)
# Space: O(1)
#
# Given a sorted linked list, delete all duplicates such that each element appear only once.
# 
# For example,
# Given 1->1->2, return 1->2.
# Given 1->1->2->3->3, return 1->2->3.
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
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        current = head
        while current and current.next:
            next = current.next
            if current.val == next.val:
                current.next = current.next.next
            else:
                current = next
        return head

if __name__ == "__main__":
    head, head.next, head.next.next = ListNode(1), ListNode(1), ListNode(2)
    head.next.next.next, head.next.next.next.next = ListNode(3), ListNode(3)
    print Solution().deleteDuplicates(head)
        