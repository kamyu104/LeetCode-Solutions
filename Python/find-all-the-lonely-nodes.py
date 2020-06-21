# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def getLonelyNodes(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        stk = [root]
        while stk:
            node = stk.pop()
            if not node:
                continue
            if node.left and not node.right:
                result.append(node.left.val)
            elif node.right and not node.left:
                result.append(node.right.val)
            stk.append(node.right)
            stk.append(node.left)
        return result


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def getLonelyNodes(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(node, result):
            if not node:
                return
            if node.left and not node.right:
                result.append(node.left.val)
            elif node.right and not node.left:
                result.append(node.right.val)
            dfs(node.left, result)
            dfs(node.right, result)

        result = []
        dfs(root, result)
        return result
