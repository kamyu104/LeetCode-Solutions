# Time:  O(n * k)
# Space: O(n + h * k)

# iterative dfs, tree dp
class Solution(object):
    def subtreeInversionSum(self, edges, nums, k):
        """
        :type edges: List[List[int]]
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def iter_dfs():
            result = []
            stk = [(1, (0, -1, result))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    ret[:] = [[nums[u]]*k, [nums[u]]*k]
                    stk.append((4, (u, p, ret)))
                    stk.append((2, (u, p, 0, ret)))
                elif step == 2:
                    u, p, i, ret = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, p, i+1, ret)))
                    if v == p:
                        continue
                    new_ret = []
                    stk.append((3, (new_ret, ret)))
                    stk.append((1, (v, u, new_ret)))
                elif step == 3:
                    new_ret, ret = args
                    new_dp1, new_dp2 = new_ret
                    dp1, dp2 = ret
                    for i in xrange(k//2):
                        dp1[i] = max(dp1[i]+new_dp1[(k-2)-i], dp1[(k-2)-i]+new_dp1[i])
                        dp2[i] = min(dp2[i]+new_dp2[(k-2)-i], dp2[(k-2)-i]+new_dp2[i])
                    for i in xrange(k//2, k):
                        dp1[i] += new_dp1[i]
                        dp2[i] += new_dp2[i]
                    for i in reversed(xrange(k-1)):
                        dp1[i] = max(dp1[i], dp1[i+1])
                        dp2[i] = min(dp2[i], dp2[i+1])
                elif step == 4:
                    u, p, ret = args
                    dp1, dp2 = ret
                    dp1.insert(0, max(dp1[0], -dp2[-1]))
                    dp2.insert(0, min(dp2[0], -dp1[-1]))
                    dp1.pop()
                    dp2.pop()
            return result[0][0]

        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(n * k)
# Space: O(n + h * k)
# dfs, tree dp
class Solution2(object):
    def subtreeInversionSum(self, edges, nums, k):
        """
        :type edges: List[List[int]]
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def dfs(u, p):
            dp1, dp2 = [nums[u]]*k, [nums[u]]*k
            for v in adj[u]:
                if v == p:
                    continue
                new_dp1, new_dp2 = dfs(v, u)
                for i in xrange(k//2):
                    dp1[i] = max(dp1[i]+new_dp1[(k-2)-i], dp1[(k-2)-i]+new_dp1[i])
                    dp2[i] = min(dp2[i]+new_dp2[(k-2)-i], dp2[(k-2)-i]+new_dp2[i])
                for i in xrange(k//2, k):
                    dp1[i] += new_dp1[i]
                    dp2[i] += new_dp2[i]
                for i in reversed(xrange(k-1)):
                    dp1[i] = max(dp1[i], dp1[i+1])
                    dp2[i] = min(dp2[i], dp2[i+1])
            dp1.insert(0, max(dp1[0], -dp2[-1]))
            dp2.insert(0, min(dp2[0], -dp1[-1]))
            dp1.pop()
            dp2.pop()
            return dp1, dp2

        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp1, _ = dfs(0, -1)
        return dp1[0]
