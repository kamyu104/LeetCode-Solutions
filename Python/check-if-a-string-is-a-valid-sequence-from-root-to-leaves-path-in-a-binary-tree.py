# Time:  O(n)
# Space: O(w)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# bfs solution
class Solution(object):
    def isValidSequence(self, root, arr):
        """
        :type root: TreeNode
        :type arr: List[int]
        :rtype: bool
        """
        q = [root]
        for depth in xrange(len(arr)):
            new_q = []
            while q:
                node = q.pop()
                if not node or node.val != arr[depth]:
                    continue
                if depth+1 == len(arr) and node.left == node.right:
                    return True
                new_q.extend(child for child in (node.left, node.right))
            q = new_q
        return False


# Time:  O(n)
# Space: O(h)
# dfs solution with stack
class Solution2(object):
    def isValidSequence(self, root, arr):
        """
        :type root: TreeNode
        :type arr: List[int]
        :rtype: bool
        """
        s = [(root, 0)]
        while s:
            node, depth = s.pop()
            if not node or depth == len(arr) or node.val != arr[depth]:
                continue
            if depth+1 == len(arr) and node.left == node.right:
                return True
            s.append((node.right, depth+1))
            s.append((node.left, depth+1))
        return False


# Time:  O(n)
# Space: O(h)
# dfs solution with recursion
class Solution3(object):
    def isValidSequence(self, root, arr):
        """
        :type root: TreeNode
        :type arr: List[int]
        :rtype: bool
        """
        def dfs(node, arr, depth):
            if not node or depth == len(arr) or node.val != arr[depth]:
                return False
            if depth+1 == len(arr) and node.left == node.right:
                return True
            return dfs(node.left, arr, depth+1) or dfs(node.right, arr, depth+1)

        return dfs(root, arr, 0)
