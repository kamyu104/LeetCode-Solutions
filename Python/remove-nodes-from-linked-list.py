# Time:  O(n)
# Space: O(n)

class ListNode(object):
    def __init__(self, val=0, next=None):
        pass


# mono stack
class Solution(object):
    def removeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        stk = []
        while head:
            while stk and stk[-1].val < head.val:
                stk.pop()
            if stk:
                stk[-1].next = head
            stk.append(head)
            head = head.next
        return stk[0]
