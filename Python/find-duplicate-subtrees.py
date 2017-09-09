# Time:  O(n)
# Space: O(n)

# Given a binary tree, return all duplicate subtrees.
# For each kind of duplicate subtrees, you only need to return the root node of any one of them.
#
# Two trees are duplicate if they have the same structure with same node values.
#
# Example 1: 
#         1
#        / \
#       2   3
#      /   / \
#     4   2   4
#        /
#       4
# The following are two duplicate subtrees:
#       2
#      /
#     4
# and
#     4
# Therefore, you need to return above trees' root in the form of a list.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def getid(root, result):
            if root:
                id = lookup[root.val, getid(root.left, result), getid(root.right, result)]
                result[id].append(root)
                return id
        result = collections.defaultdict(list)
        lookup = collections.defaultdict()
        lookup.default_factory = lookup.__len__
        getid(root, result)
        return [roots[0] for roots in result.values() if len(roots) > 1]


# Time:  O(n * h)
# Space: O(n * h)
class Solution2(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        def postOrderTraversal(node, lookup, result):
            if not node:
                return ""
            s = "(" + postOrderTraversal(node.left, lookup, result) + \
                str(node.val) + \
                postOrderTraversal(node.right, lookup, result) + \
                ")"
            if lookup[s] == 1:
                result.append(node)
            lookup[s] += 1
            return s
       
        lookup = collections.defaultdict(int)
        result = []
        postOrderTraversal(root, lookup, result)
        return result
