# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class FindElements(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        def dfs(node, v, lookup):
            if not node:
                return
            node.val = v    
            lookup.add(v)
            dfs(node.left, 2*v+1, lookup)
            dfs(node.right, 2*v+2, lookup)

        self.__lookup = set()
        dfs(root, 0, self.__lookup)

    def find(self, target):
        """
        :type target: int
        :rtype: bool
        """
        return target in self.__lookup 
