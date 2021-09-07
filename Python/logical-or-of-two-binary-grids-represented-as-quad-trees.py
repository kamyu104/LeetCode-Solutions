# Time:  O(n)
# Space: O(h)

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

