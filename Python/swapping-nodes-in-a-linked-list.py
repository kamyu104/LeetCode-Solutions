# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        pass


class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        left, right, curr = None, None, head
        while curr:
            k -= 1
            if right:
                right = right.next
            if k == 0:
                left = curr
                right = head
            curr = curr.next
        left.val, right.val = right.val, left.val
        return head
