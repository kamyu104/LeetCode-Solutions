# Time:  O(n)
# Space: O(h)

# Given an n-ary tree, return the preorder traversal of its nodes' values.
#
# For example, given a 3-ary tree: 
# Return its preorder traversal as: [1,3,5,6,2,4].
#
# Note: Recursive solution is trivial, could you do it iteratively?
    
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root:
            return []
        result, stack = [], [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            for child in reversed(node.children):
                if child:
                    stack.append(child)
        return result


class Solution2(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        def dfs(root, result):
            result.append(root.val)
            for child in root.children:
                if child:
                    dfs(child, result)
        
        result = []
        if root:
            dfs(root, result)
        return result
