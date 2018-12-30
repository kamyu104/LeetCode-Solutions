# Time:  O(n)
# Space: O(n)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        # https://github.com/kamyu104/LintCode/blob/master/C++/max-tree.cpp
        nodeStack = []
        for num in nums:
            node = TreeNode(num)
            while nodeStack and num > nodeStack[-1].val:
                node.left = nodeStack.pop()
            if nodeStack:
                nodeStack[-1].right = node
            nodeStack.append(node)
        return nodeStack[0]

