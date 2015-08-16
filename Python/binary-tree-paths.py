# Time:  O(n * h)
# Space: O(h)
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        result, path = [], []
        self.binaryTreePathsRecu(root, path, result)
        return result
    
    def binaryTreePathsRecu(self, node, path, result):
        if node is None:
            return

        if node.left is node.right is None:
            ans = ""
            for n in path:
                ans += str(n.val) + "->"
            resault.append(ans + str(node.val))

        if node.left:
            path.append(node)
            self.binaryTreePathsRecu(node.left, path, result)
            path.pop()

        if node.right:
            path.append(node)
            self.binaryTreePathsRecu(node.right, path, result)
            path.pop()
