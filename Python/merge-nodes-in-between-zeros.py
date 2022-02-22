# Time:  O(n)
# Space: O(1)

class ListNode(object):
    def __init__(self, val=0, next=None):
        pass


# linked list
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        curr, zero = head.next, head
        while curr:
            if curr.val:
                zero.val += curr.val
            else:
                zero.next = curr if curr.next else None
                zero = curr
            curr = curr.next
        return head
