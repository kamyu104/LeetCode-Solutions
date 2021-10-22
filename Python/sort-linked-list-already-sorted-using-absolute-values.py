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
        curr = head
        while curr:
            nxt = curr.next
            if curr.val >= 0:
                curr.next = None
                tail.next = curr
                tail = curr
            else:
                curr.next = dummy.next
                dummy.next = curr
                if tail is dummy:
                    tail = curr
            curr = nxt
        return dummy.next

    
# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def sortLinkedList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        curr = head
        head = tail = None
        while curr:
            nxt = curr.next
            if curr.val >= 0:
                curr.next = None
                if tail:
                    tail.next = curr
                tail = curr
                if head is None:
                    head = tail
            else:
                curr.next = head if head else None
                head = curr
                if tail is None:
                    tail = head
            curr = nxt
        return head
