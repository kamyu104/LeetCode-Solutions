# Time:  O(m + n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        pass


class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        prev_first, last = None, list1
        for i in xrange(b):
            if i == a-1:
                prev_first = last
            last = last.next
        prev_first.next = list2
        while list2.next:
            list2 = list2.next
        list2.next = last.next
        last.next = None
        return list1
