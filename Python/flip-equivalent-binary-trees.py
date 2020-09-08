# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


import collections


# bfs solution
class Solution(object):
    def flipEquiv(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        dq1, dq2 = collections.deque([root1]), collections.deque([root2])
        while dq1 and dq2:
            node1, node2 = dq1.pop(), dq2.pop()
            if not node1 and not node2:
                continue 
            if not node1 or not node2 or node1.val != node2.val:
                return False
            if (not node1.left and not node2.right) or \
               (node1.left and node2.right and node1.left.val == node2.right.val):
                dq1.extend([node1.right, node1.left])
            else:
                dq1.extend([node1.left, node1.right])
            dq2.extend([node2.left, node2.right])
        return not dq1 and not dq2


# Time:  O(n)
# Space: O(h)
# iterative dfs solution
class Solution2(object):
    def flipEquiv(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        stk1, stk2 = [root1], [root2]
        while stk1 and stk2:
            node1, node2 = stk1.pop(), stk2.pop()
            if not node1 and not node2:
                continue 
            if not node1 or not node2 or node1.val != node2.val:
                return False
            if (not node1.left and not node2.right) or \
               (node1.left and node2.right and node1.left.val == node2.right.val):
                stk1.extend([node1.right, node1.left])
            else:
                stk1.extend([node1.left, node1.right])
            stk2.extend([node2.left, node2.right])
        return not stk1 and not stk2


# Time:  O(n)
# Space: O(h)
# recursive dfs solution
class Solution3(object):
    def flipEquiv(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        if not root1 and not root2:
            return True
        if not root1 or not root2 or root1.val != root2.val:
            return False

        return (self.flipEquiv(root1.left, root2.left) and
                self.flipEquiv(root1.right, root2.right) or
                self.flipEquiv(root1.left, root2.right) and
                self.flipEquiv(root1.right, root2.left))
