# Time:  O(n)
# Space: O(h)

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.depth(root, 0)[1]
    
    def depth(self, root, diameter):
        if not root: 
            return 0, diameter
        left, diameter = self.depth(root.left, diameter)
        right, diameter = self.depth(root.right, diameter)
        return 1 + max(left, right), max(diameter, left + right)

