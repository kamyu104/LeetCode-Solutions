# Time:  O(n)
# Space: O(h)

# iterative dfs
class Solution(object):
    def countDominantNodes(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def iter_dfs():
            ret = [0]*2
            stk = [(1, (root, ret))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, ret = args
                    if u is None:
                        continue
                    ret1 = [0]*2
                    ret2 = [0]*2
                    stk.append((2, (u, ret1, ret2, ret)))
                    stk.append((1, (u.right, ret2)))
                    stk.append((1, (u.left, ret1)))
                elif step == 2:
                    u, ret1, ret2, ret = args
                    mx = max(ret1[1], ret2[1], u.val)
                    ret[:] = [ret1[0]+ret2[0]+(1 if mx == u.val else 0), mx]
            return ret[0]
        
        return iter_dfs()


# Time:  O(n)
# Space: O(h)
# dfs
class Solution2(object):
    def countDominantNodes(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(u):
            if u is None:
                return [0]*2
            cnt1, mx1 = dfs(u.left)
            cnt2, mx2 = dfs(u.right)
            mx = max(mx1, mx2, u.val)
            return [cnt1+cnt2+(1 if mx == u.val else 0), mx]
        
        return dfs(root)[0]
