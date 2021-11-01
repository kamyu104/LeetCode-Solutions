# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        first = last = 0
        result = float("inf")
        i, prev = 0, head.val
        while head.next:
            if max(prev, head.next.val) < head.val or min(prev, head.next.val) > head.val:
                if not first:
                    first = i
                if last:
                    result = min(result, i-last)
                last = i
            i += 1
            prev = head.val
            head = head.next
        return [result, last-first] if first != last else [-1, -1]
