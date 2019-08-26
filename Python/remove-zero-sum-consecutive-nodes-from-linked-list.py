# Time:  O(n)
# Space: O(n)

import collections


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr = dummy = ListNode(0)
        dummy.next = head
        prefix = 0
        lookup = collections.OrderedDict()
        while curr:
            prefix += curr.val
            node = lookup.get(prefix, curr)
            while prefix in lookup:
                lookup.popitem()
            lookup[prefix] = node
            node.next = curr.next
            curr = curr.next
        return dummy.next
