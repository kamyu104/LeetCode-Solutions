# Time:  O(n)
# Space: O(h)
#
# Invert a binary tree.
#
#      4
#    /   \
#   2     7
#  / \   / \
# 1   3 6   9
# to
#      4
#    /   \
#   7     2
#  / \   / \
# 9   6 3   1
#

# Time:  O(n)
# Space: O(w), w is the max number of the nodes of the levels.
# BFS solution.
class Queue:
    def __init__(self):
        self.data = collections.deque()
        
    def push(self, x):
        self.data.append(x)
    
    def peek(self):
        return self.data[0]
    
    def pop(self):
        return self.data.popleft()
    
    def size(self):
        return len(self.data)
    
    def empty(self):
        return len(self.data) == 0
        

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is not None:
            nodes = Queue()
            nodes.push(root)
            while not nodes.empty():
                node = nodes.pop()
                node.left, node.right = node.right, node.left
                if node.left is not None:
                    nodes.push(node.left)
                if node.right is not None:
                    nodes.push(node.right)
        
        return root
  
# Time:  O(n)
# Space: O(h)
# Stack solution.
class Solution2:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is not None:
            nodes = []
            nodes.append(root)
            while nodes:
                node = nodes.pop()
                node.left, node.right = node.right, node.left
                if node.left is not None:
                    nodes.append(node.left)
                if node.right is not None:
                    nodes.append(node.right)
        
        return root
  
# Time:  O(n)
# Space: O(h)
# DFS, Recursive solution.
class Solution3:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is not None:
            root.left, root.right = self.invertTree(root.right), \
                                    self.invertTree(root.left)
        
        return root
