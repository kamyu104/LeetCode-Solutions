# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        pass


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def iter_dfs(node, p, q):
            result = None
            stk = [(1, (node, [0]))]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, ret = params
                    if not node:
                        continue
                    ret1, ret2 = [0], [0]
                    stk.append((2, (node, ret1, ret2, ret)))
                    stk.append((1, (node.right, ret2)))
                    stk.append((1, (node.left, ret1)))
                elif step == 2:
                    node, ret1, ret2, ret = params
                    curr = int(node == p or node == q)
                    if curr+ret1[0]+ret2[0] == 2 and not result:
                        result = node
                    ret[0] = curr+ret1[0]+ret2[0]
            return result

        return iter_dfs(root, p, q)


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """        
        def dfs(node, p, q, result):
            if not node:
                return 0
            left = dfs(node.left, p, q, result)
            right = dfs(node.right, p, q, result)
            curr = int(node == p or node == q)
            if curr+left+right == 2 and not result[0]:
                result[0] = node
            return curr+left+right

        result = [0]
        dfs(root, p, q, result)
        return result[0]

