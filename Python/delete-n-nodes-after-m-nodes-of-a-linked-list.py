# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def deleteNodes(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        head = dummy = ListNode(next=head)
        while head:
            for _ in xrange(m):
                if not head.next:
                    return dummy.next
                head = head.next
            prev = head
            for _ in xrange(n):
                if not head.next:
                    prev.next = None
                    return dummy.next
                head = head.next
            prev.next = head.next
        return dummy.next
