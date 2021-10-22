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
        tail = dummy = ListNode()
        while head:
            nxt = head.next
            if head.val >= 0:
                head.next = None
                tail.next = head
                tail = head
            else:
                head.next = dummy.next
                dummy.next = head
                if tail is dummy:
                    tail = head
            head = nxt
        return dummy.next
