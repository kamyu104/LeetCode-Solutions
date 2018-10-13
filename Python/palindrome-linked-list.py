# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        reverse, fast = None, head
        # Reverse the first half part of the list.
        while fast and fast.next:
            fast = fast.next.next
            head.next, reverse, head = reverse, head, head.next

        # If the number of the nodes is odd,
        # set the head of the tail list to the next of the median node.
        tail = head.next if fast else head

        # Compare the reversed first half list with the second half list.
        # And restore the reversed first half list.
        is_palindrome = True
        while reverse:
            is_palindrome = is_palindrome and reverse.val == tail.val
            reverse.next, head, reverse = head, reverse, reverse.next
            tail = tail.next

        return is_palindrome

