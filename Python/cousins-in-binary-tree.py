# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        def dfs(root, x, depth, parent):
            if not root:
                return False
            if root.val == x:
                return True
            depth[0] += 1
            prev_parent, parent[0] = parent[0], root
            if dfs(root.left, x, depth, parent):
                return True
            parent[0] = root
            if dfs(root.right, x, depth, parent):
                return True
            parent[0] = prev_parent
            depth[0] -= 1
            return False
        
        depth_x, depth_y = [0], [0]
        parent_x, parent_y = [None], [None]
        return dfs(root, x, depth_x, parent_x) and \
               dfs(root, y, depth_y, parent_y) and \
               depth_x[0] == depth_y[0] and \
               parent_x[0] != parent_y[0]
                
        
