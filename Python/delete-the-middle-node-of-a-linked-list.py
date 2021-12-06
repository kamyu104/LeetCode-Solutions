# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = ListNode()
        dummy.next = head
        slow = fast = dummy
        while fast.next and fast.next.next:
            slow, fast = slow.next, fast.next.next
        slow.next = slow.next.next
        return dummy.next
