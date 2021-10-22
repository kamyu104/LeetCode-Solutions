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
        dummy = ListNode(next=head)
        tail, curr = head, head.next
        head.next = None
        while curr:
            nxt = curr.next
            if curr.val >= 0:
                curr.next = None
                tail.next = curr
                tail = curr
            else:
                curr.next = dummy.next
                dummy.next = curr
            curr = nxt
        return dummy.next

    
# Time:  O(n)
# Space: O(1)
class Solution(object):
    def sortLinkedList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        tail = head
        curr = head.next
        head.next = None
        while curr:
            nxt = curr.next
            if curr.val >= 0:
                curr.next = None
                tail.next = curr
                tail = curr
            else:
                curr.next = head
                head = curr
            curr = nxt
        return head
