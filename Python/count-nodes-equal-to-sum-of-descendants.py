# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


class Solution(object):
    def equalToDescendants(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def iter_dfs(node):
            result = 0
            stk = [(1, [node, [0]])]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    node, ret = args
                    if not node:
                        continue
                    ret1, ret2 = [0], [0]
                    stk.append((2, [node, ret1, ret2, ret]))
                    stk.append((1, [node.right, ret2]))
                    stk.append((1, [node.left, ret1]))
                elif step == 2:
                    node, ret1, ret2, ret = args
                    if node.val == ret1[0]+ret2[0]:
                        result += 1
                    ret[0] = ret1[0]+ret2[0]+node.val
            return result

        return iter_dfs(root)


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def equalToDescendants(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node, result):
            if not node:
                return 0
            total = dfs(node.left, result) + dfs(node.right, result)
            if node.val == total:
                result[0] += 1
            return total+node.val

        result = [0]
        dfs(root, result)
        return result[0]
