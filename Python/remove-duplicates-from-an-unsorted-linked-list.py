# Time:  O(n)
# Space: O(n)

import collections


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def deleteDuplicatesUnsorted(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = collections.defaultdict(int)
        curr = head
        while curr:
            count[curr.val] += 1
            curr = curr.next
        curr = dummy = ListNode(0, head)
        while curr.next:
            if count[curr.next.val] == 1:
                curr = curr.next
            else:
                curr.next = curr.next.next
        return dummy.next
