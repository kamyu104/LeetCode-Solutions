# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def pseudoPalindromicPaths (self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = 0
        stk = [(root, 0)]
        while stk:
            node, count = stk.pop()
            if not node:
                continue
            count ^= 1 << (node.val-1)
            result += int(node.left == node.right and count&(count-1) == 0)
            stk.append((node.right, count))
            stk.append((node.left, count))
        return result
    

# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def pseudoPalindromicPaths (self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node, count):
            if not root:
                return 0
            count ^= 1 << (node.val-1)
            return int(node.left == node.right and count&(count-1) == 0) + \
                   dfs(node.left, count) + dfs(node.right, count)
        return dfs(root, 0)
