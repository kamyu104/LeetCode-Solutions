# Time:  O(n)
# Space: O(n)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        result, stk = [], []
        while head:
            while stk and stk[-1][1] < head.val:
                result[stk.pop()[0]] = head.val
            stk.append([len(result), head.val])
            result.append(0)
            head = head.next
        return result
