# Time:  O(n)
# Space: O(h)

# A quadtree is a tree data in which each internal node has exactly four children:
# topLeft, topRight, bottomLeft and bottomRight.
# Quad trees are often used to partition a two-dimensional space by
# recursively subdividing it into four quadrants or regions.
#
# We want to store True/False information in our quad tree.
# The quad tree is used to represent a N * N boolean grid. For each node,
# it will be subdivided into four children nodes until the values in the region
# it represents are all the same. Each node has another two boolean attributes :
# isLeaf and val. isLeaf is true if and only if the node is a leaf node.
# The val attribute for a leaf node contains the value of the region it represents.
#
# For example, below are two quad trees A and B:
#
# A:
# +-------+-------+   T: true
# |       |       |   F: false
# |   T   |   T   |
# |       |       |
# +-------+-------+
# |       |       |
# |   F   |   F   |
# |       |       |
# +-------+-------+
# topLeft: T
# topRight: T
# bottomLeft: F
# bottomRight: F
#
# B:               
# +-------+---+---+
# |       | F | F |
# |   T   +---+---+
# |       | T | T |
# +-------+---+---+
# |       |       |
# |   T   |   F   |
# |       |       |
# +-------+-------+
# topLeft: T
# topRight:
#      topLeft: F
#      topRight: F
#      bottomLeft: T
#      bottomRight: T
# bottomLeft: T
# bottomRight: F
#
# Your task is to implement a function that will take two quadtrees and
# return a quadtree that represents the logical OR (or union) of the two trees.
#
# A:                 B:                 C (A or B):
# +-------+-------+  +-------+---+---+  +-------+-------+
# |       |       |  |       | F | F |  |       |       |
# |   T   |   T   |  |  T    +---+---+  |   T   |   T   |
# |       |       |  |       | T | T |  |       |       |
# +-------+-------+  +-------+---+---+  +-------+-------+
# |       |       |  |       |       |  |       |       |
# |   F   |   F   |  |   T   |   F   |  |   T   |   F   |
# |       |       |  |       |       |  |       |       |
# +-------+-------+  +-------+-------+  +-------+-------+
#
# Note:
# - N is guaranteened to be a power of 2.
# - If you want to know more about the quad tree, you can refer to its wiki.
# - The logic OR operation is define as this: "A or B" is true if A is true,
#   or if B is true, or if both A and B are true.
    
# Definition for a QuadTree node.
class Node(object):
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution(object):
    def intersect(self, quadTree1, quadTree2):
        """
        :type quadTree1: Node
        :type quadTree2: Node
        :rtype: Node
        """
        if quadTree1.isLeaf:
            return quadTree1 if quadTree1.val else quadTree2
        elif quadTree2.isLeaf:
            return quadTree2 if quadTree2.val else quadTree1
        topLeftNode = self.intersect(quadTree1.topLeft, quadTree2.topLeft)
        topRightNode = self.intersect(quadTree1.topRight, quadTree2.topRight)
        bottomLeftNode = self.intersect(quadTree1.bottomLeft, quadTree2.bottomLeft)
        bottomRightNode = self.intersect(quadTree1.bottomRight, quadTree2.bottomRight)
        if topLeftNode.isLeaf and topRightNode.isLeaf and \
           bottomLeftNode.isLeaf and bottomRightNode.isLeaf and \
           topLeftNode.val == topRightNode.val == bottomLeftNode.val == bottomRightNode.val:
            return Node(topLeftNode.val, True, None, None, None, None)
        return Node(True, False, topLeftNode, topRightNode, bottomLeftNode, bottomRightNode)
