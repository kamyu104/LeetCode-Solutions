# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# dfs
class Solution(object):
    def averageOfSubtree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def iter_dfs(root):
            result = 0
            stk = [(1, (root, [0]*2))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    node, ret = args
                    if not node:
                        continue
                    ret1, ret2 = [0]*2, [0]*2
                    stk.append((2, (node, ret1, ret2, ret)))
                    stk.append((1, (node.right, ret2)))
                    stk.append((1, (node.left, ret1)))
                elif step == 2:
                    node, ret1, ret2, ret = args
                    ret[0] = ret1[0]+ret2[0]+node.val
                    ret[1] = ret1[1]+ret2[1]+1
                    result += int(ret[0]//ret[1] == node.val)
            return result
        
        return iter_dfs(root)


# Time:  O(n)
# Space: O(h)
# dfs
class Solution2(object):
    def averageOfSubtree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node):
            if not node:
                return [0]*3
            left = dfs(node.left)
            right = dfs(node.right)
            return [left[0]+right[0]+node.val,
                    left[1]+right[1]+1,
                    left[2]+right[2]+int((left[0]+right[0]+node.val)//(left[1]+right[1]+1) == node.val)]
        
        return dfs(root)[2]
