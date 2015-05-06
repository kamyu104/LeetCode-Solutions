# Time:  O(n)
# Space: O(1)
#
# Reverse a singly linked list.
#
# click to show more hints.
#
# Hint:
# A linked list can be reversed either iteratively or recursively. Could you implement both?
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))

# Iterative solution.
class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        dummy = ListNode(float("-inf"))
        while head:
            dummy.next, head.next, head = head, dummy.next, head.next
        return dummy.next

# Time:  O(n)
# Space: O(n)
# Recursive solution.  
class Solution2:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        [begin, end] = self.reverseListRecu(head)
        return begin
    
    def reverseListRecu(self, head):
        if not head:
            return [None, None]
            
        [begin, end] = self.reverseListRecu(head.next)
        
        if end:
            end.next = head
            head.next = None
            return [begin, head]
        else:
            return [head, head]
        
if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution2().reverseList(head)