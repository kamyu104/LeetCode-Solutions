# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        pass


class Solution(object):
    def lowestCommonAncestor(self, root, nodes):
        """
        :type root: TreeNode
        :type nodes: List[TreeNode]
        """
        def iter_dfs(root, lookup):
            result = [0]
            stk = [(1, (root, result))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    node, ret = args
                    if not node or node in lookup:
                        ret[0] = node
                        continue
                    ret1, ret2 = [None], [None]
                    stk.append((2, (node, ret1, ret2, ret)))
                    stk.append((1, (node.right, ret2)))
                    stk.append((1, (node.left, ret1)))
                elif step == 2:
                    node, ret1, ret2, ret = args
                    if ret1[0] and ret2[0]:
                        ret[0] = node
                    else:
                        ret[0] = ret1[0] or ret2[0]
            return result[0]
        
        return iter_dfs(root, set(nodes))


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def lowestCommonAncestor(self, root, nodes):
        """
        :type root: TreeNode
        :type nodes: List[TreeNode]
        """
        def dfs(node, lookup):
            if not node or node in lookup:
                return node
            left, right = dfs(node.left, lookup), dfs(node.right, lookup)
            if left and right:
                return node
            return left or right
        
        return dfs(root, set(nodes))
