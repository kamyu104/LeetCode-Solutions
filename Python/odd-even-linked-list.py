# Time:  O(n)
# Space: O(1)

# Given a singly linked list, group all odd nodes
# together followed by the even nodes.
# Please note here we are talking about the node number
# and not the value in the nodes.
#
# You should try to do it in place. The program should run
# in O(1) space complexity and O(nodes) time complexity.
#
# Example:
# Given 1->2->3->4->5->NULL,
# return 1->3->5->2->4->NULL.
#
# Note:
# The relative order inside both the even and odd groups
# should remain as it was in the input.
# The first node is considered odd, the second node even
# and so on ...

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head:
            odd_tail, cur = head, head.next
            while cur and cur.next:
                even_head = odd_tail.next
                odd_tail.next = cur.next
                odd_tail = odd_tail.next
                cur.next = odd_tail.next
                odd_tail.next = even_head
                cur = cur.next
        return head
