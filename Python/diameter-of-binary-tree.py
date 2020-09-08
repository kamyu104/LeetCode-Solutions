# Time:  O(n)
# Space: O(h)

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def iter_dfs(node):
            result = 0
            max_depth = [0]
            stk = [(1, [node, max_depth])]
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
                    result = max(result, ret1[0]+ret2[0])
                    ret[0] = 1+max(ret1[0], ret2[0])
            return result
        
        return iter_dfs(root)


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root):
            if not root: 
                return 0, 0
            left_d, left_h = dfs(root.left)
            right_d, right_h = dfs(root.right)
            return max(left_d, right_d, left_h+right_h), 1+max(left_h, right_h)
 
        return dfs(root)[0]
