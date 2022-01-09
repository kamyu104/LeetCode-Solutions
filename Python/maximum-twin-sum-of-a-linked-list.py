# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def pairSum(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        def reverseList(head):
            dummy = ListNode()
            while head:
                dummy.next, head.next, head = head, dummy.next, head.next
            return dummy.next

        dummy = ListNode(next=head)
        slow = fast = dummy
        while fast.next and fast.next.next:
            slow, fast = slow.next, fast.next.next
        result = 0
        head2 = reverseList(slow)
        while head:
            result = max(result, head.val+head2.val)
            head, head2 = head.next, head2.next
        return result
