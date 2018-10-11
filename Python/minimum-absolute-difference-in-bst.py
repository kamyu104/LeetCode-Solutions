# Time:  O(n)
# Space: O(h)

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def inorderTraversal(root, prev, result):
            if not root:
                return (result, prev)

            result, prev = inorderTraversal(root.left, prev, result)
            if prev: result = min(result, root.val - prev.val)
            return inorderTraversal(root.right, root, result)

        return inorderTraversal(root, None, float("inf"))[0]

