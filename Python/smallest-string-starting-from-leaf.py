# Time:  O(n + l * h), l is the number of leaves
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        def dfs(node, candidate, result):
            if not node:
                return

            candidate.append(chr(ord('a') + node.val))
            if not node.left and not node.right:
                result[0] = min(result[0], "".join(reversed(candidate)))
            dfs(node.left, candidate, result)
            dfs(node.right, candidate, result)
            candidate.pop()

        result = ["~"]
        dfs(root, [], result)
        return result[0]
