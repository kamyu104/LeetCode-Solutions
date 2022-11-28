# Time:  O(n + qlogn)
# Space: O(n)

import bisect


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# iterative dfs, binary search
class Solution(object):
    def closestNodes(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[List[int]]
        """
        def iter_dfs():
            inorder = []
            stk = [(1, root)]
            while stk:
                step, node = stk.pop()
                if step == 1:
                    if not node:
                        continue
                    stk.append((1, node.right))
                    stk.append((2, node))
                    stk.append((1, node.left))
                elif step == 2:
                    inorder.append(node.val)
            return inorder

        inorder = iter_dfs()
        result = []
        for q in queries:
            i = bisect.bisect_left(inorder, q)
            if i == len(inorder):
                result.append([inorder[i-1], -1])
            elif inorder[i] == q:
                result.append([inorder[i], inorder[i]])
            elif i-1 >= 0:
                result.append([inorder[i-1], inorder[i]])
            else:
                result.append([-1, inorder[i]])
        return result


# Time:  O(n + qlogn)
# Space: O(n)
import bisect


# dfs, binary search
class Solution2(object):
    def closestNodes(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[List[int]]
        """
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            inorder.append(node.val)
            dfs(node.right)

        inorder = []
        dfs(root)
        result = []
        for q in queries:
            i = bisect.bisect_left(inorder, q)
            if i == len(inorder):
                result.append([inorder[i-1], -1])
            elif inorder[i] == q:
                result.append([inorder[i], inorder[i]])
            elif i-1 >= 0:
                result.append([inorder[i-1], inorder[i]])
            else:
                result.append([-1, inorder[i]])
        return result
