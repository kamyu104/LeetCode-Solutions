# Time:  O(n)
# Space: O(h), h is height of binary tree

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        def iter_dfs(node):
            result = float("-inf")
            max_sum = [0]
            stk = [(1, [node, max_sum])]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, ret = params
                    if not node:
                        continue
                    ret1, ret2 = [0], [0]
                    stk.append((2, [node, ret1, ret2, ret]))
                    stk.append((1, [node.right, ret2]))
                    stk.append((1, [node.left, ret1]))
                elif step == 2:
                    node, ret1, ret2, ret = params
                    result = max(result, node.val+max(ret1[0], 0)+max(ret2[0], 0))
                    ret[0] = node.val+max(ret1[0], ret2[0], 0)
            return result
        
        return iter_dfs(root)


# Time:  O(n)
# Space: O(h), h is height of binary tree
class Solution2(object):
    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        def dfs(node):
            if not node:
                return (float("-inf"), 0)
            max_left, curr_left = dfs(node.left)
            max_right, curr_right = dfs(node.right)
            return (max(max_left, max_right, node.val+max(curr_left, 0)+max(curr_right, 0)),
                    node.val+max(curr_left, curr_right, 0))
        
        return dfs(root)[0]
