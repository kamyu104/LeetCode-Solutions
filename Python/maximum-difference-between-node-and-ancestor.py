# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# iterative stack solution
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        stack = [(root, 0, float("inf"))]
        while stack:
            node, mx, mn = stack.pop()
            if not node:
                continue
            result = max(result, mx-node.val, node.val-mn)
            mx = max(mx, node.val)
            mn = min(mn, node.val)
            stack.append((node.left, mx, mn))
            stack.append((node.right, mx, mn))
        return result


# Time:  O(n)
# Space: O(h)
# recursive solution
class Solution2(object):
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def maxAncestorDiffHelper(node, mx, mn): 
            if not node:
                return 0
            result = max(mx-node.val, node.val-mn)
            mx = max(mx, node.val)
            mn = min(mn, node.val)
            result = max(result, maxAncestorDiffHelper(node.left, mx, mn))
            result = max(result, maxAncestorDiffHelper(node.right, mx, mn))
            return result

        return maxAncestorDiffHelper(root, 0, float("inf"))
