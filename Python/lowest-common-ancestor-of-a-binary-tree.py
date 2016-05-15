# Time:  O(n)
# Space: O(h)
#
# Given a binary tree, find the lowest common ancestor (LCA)
# of two given nodes in the tree.
#
# According to the definition of LCA on Wikipedia: “The lowest
# common ancestor is defined between two nodes v and w as the
# lowest node in T that has both v and w as descendants (where we
# allow a node to be a descendant of itself).”
#
#         _______3______
#       /              \
#     ___5__          ___1__
#   /      \        /      \
#   6      _2       0       8
#          /  \
#          7   4
# For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
# Another example is LCA of nodes 5 and 4 is 5, since a node can be a
# descendant of itself according to the LCA definition.
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        if root in (None, p, q):
            return root

        left, right = [self.lowestCommonAncestor(child, p, q) \
                         for child in (root.left, root.right)]
        # 1. If the current subtree contains both p and q,
        #    return their LCA.
        # 2. If only one of them is in that subtree,
        #    return that one of them.
        # 3. If neither of them is in that subtree,
        #    return the node of that subtree.
        return root if left and right else left or right
