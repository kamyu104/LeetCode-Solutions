# Time:  O(n)
# Space: O(logn)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    head = None
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        current, length = head, 0
        while current is not None:
            current, length = current.next, length + 1
        self.head = head
        return self.sortedListToBSTRecu(0, length)

    def sortedListToBSTRecu(self, start, end):
        if start == end:
            return None
        mid = start + (end - start) / 2
        left = self.sortedListToBSTRecu(start, mid)
        current = TreeNode(self.head.val)
        current.left = left
        self.head = self.head.next
        current.right = self.sortedListToBSTRecu(mid + 1, end)
        return current

