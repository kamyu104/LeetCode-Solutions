# Time:  O(n)
# Space: O(n)

# Given a binary tree where every node has a unique value, and a target key k,
# find the value of the closest leaf node to target k in the tree.
#
# Here, closest to a leaf means the least number of edges travelled on the binary tree to reach
# any leaf of the tree. Also, a node is called a leaf if it has no children.
#
# In the following examples, the input tree is represented in flattened form row by row.
# The actual root tree given will be a TreeNode object.
#
# Example 1:
#
# Input:
# root = [1, 3, 2], k = 1
# Diagram of binary tree:
#           1
#          / \
#         3   2
#
# Output: 2 (or 3)
#
# Explanation: Either 2 or 3 is the closest leaf node to the target of 1.
# Example 2:
#
# Input:
# root = [1], k = 1
# Output: 1
#
# Explanation: The closest leaf node is the root node itself.
# Example 3:
#
# Input:
# root = [1,2,3,4,null,null,null,5,null,6], k = 2
# Diagram of binary tree:
#              1
#             / \
#            2   3
#           /
#          4
#         /
#        5
#       /
#      6
#
# Output: 3
# Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.
# Note:
# - root represents a binary tree with at least 1 node and at most 1000 nodes.
# - Every node has a unique node.val in range [1, 1000].
# - There exists some node in the given binary tree for which node.val == k.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections


class Solution(object):
    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def traverse(node, neighbors, leaves):
            if not node:
                return
            if not node.left and not node.right:
                leaves.add(node.val)
                return
            if node.left:
                neighbors[node.val].append(node.left.val)
                neighbors[node.left.val].append(node.val)
                traverse(node.left, neighbors, leaves)
            if node.right:
                neighbors[node.val].append(node.right.val)
                neighbors[node.right.val].append(node.val)
                traverse(node.right, neighbors, leaves)

        neighbors, leaves = collections.defaultdict(list), set()
        traverse(root, neighbors, leaves)
        q, lookup = [k], set([k])
        while q:
            next_q = []
            for u in q:
                if u in leaves:
                    return u
                for v in neighbors[u]:
                    if v in lookup:
                        continue
                    lookup.add(v)
                    next_q.append(v)
            q = next_q
        return 0
