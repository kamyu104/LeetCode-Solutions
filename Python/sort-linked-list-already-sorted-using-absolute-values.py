# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def sortLinkedList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        tail, curr, head.next = head, head.next, None
        while curr:
            if curr.val > 0:
                curr.next, tail.next, tail, curr = None, curr, curr, curr.next
            else:
                curr.next, head, curr = head, curr, curr.next
        return head
