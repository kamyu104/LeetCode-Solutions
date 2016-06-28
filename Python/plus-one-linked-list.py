# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def plusOne(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        curr = head
        while curr:
            dummy.next, curr.next, curr = curr, dummy.next, curr.next

        curr, carry = dummy.next, 1
        while curr and carry:
            curr.val += carry
            carry = curr.val / 10
            curr.val %= 10
            if carry and curr.next is None:
                curr.next = ListNode(0)
            curr = curr.next

        curr = dummy.next
        dummy.next = None
        while curr:
            dummy.next, curr.next, curr = curr, dummy.next, curr.next

        return dummy.next
