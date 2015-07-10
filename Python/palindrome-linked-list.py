# Time:  O(n)
# Space: O(1)
#
# Given a singly linked list, determine if it is a palindrome.
#
# Follow up:
# Could you do it in O(n) time and O(1) space?
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        # Reverse the first half part of the list.
        reverse, fast = None, head
        while fast and fast.next:
            fast = fast.next.next
            reverse, reverse.next, head = head, reverse, head.next

        # If the number of the nodes is odd,
        # set the head of the tail list to the next of the median node.
        tail = head.next if fast else head

        # Compare the reversed first half list with the second half list.
        # And restore the reversed first half list.
        is_palindrome = True
        while reverse:
            is_palindrome = is_palindrome and reverse.val == tail.val
            head, head.next, reverse = reverse, head, reverse.next
            tail = tail.next

        return is_palindrome
