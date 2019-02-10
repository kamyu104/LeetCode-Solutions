# Time:  O(h)
# Space: O(1)

# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right, parent):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

        
class Solution(object):
    def inorderSuccessor(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None
        
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        
        while node.parent and node.parent.right is node:
            node = node.parent
        return node.parent
