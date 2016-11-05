# Time:  O(m + n)
# Space: O(m + n)

# You are given two linked lists representing two non-negative numbers.
# The most significant digit comes first and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
# Follow up:
# What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
#
# Example:
#
# Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 8 -> 0 -> 7

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        stk1, stk2 = [], []
        while l1:
            stk1.append(l1.val)
            l1 = l1.next
        while l2:
            stk2.append(l2.val)
            l2 = l2.next

        prev, head = None, None
        sum = 0
        while stk1 or stk2:
            sum /= 10
            if stk1:
                sum += stk1.pop()
            if stk2:
                sum += stk2.pop()
            
            head = ListNode(sum % 10)
            head.next = prev
            prev = head

        if sum >= 10:
            head = ListNode(sum / 10)
            head.next = prev

        return head
