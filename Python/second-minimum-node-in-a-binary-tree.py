# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def findSecondMinimumValueHelper(root, max_heap, lookup):
            if not root:
                return
            if root.val not in lookup:
                heapq.heappush(max_heap, -root.val)
                lookup.add(root.val)
                if len(max_heap) > 2:
                    lookup.remove(-heapq.heappop(max_heap))
            findSecondMinimumValueHelper(root.left, max_heap, lookup)
            findSecondMinimumValueHelper(root.right, max_heap, lookup)

        max_heap, lookup = [], set()
        findSecondMinimumValueHelper(root, max_heap, lookup)
        if len(max_heap) < 2:
            return -1
        return -max_heap[0]
