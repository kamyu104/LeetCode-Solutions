# Time:  O(n^2)
# Space: O(n)

# dfs with recursion
class Solution(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def dfs(u, p, result):
            total = nums[u]
            for v in adj[u]:
                if v == p:
                    continue
                total ^= dfs(v, u, result)
            result.append(total)
            return total
                
        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        total = reduce(lambda x, y: x^y, nums)
        result = float("inf")
        for u, v in edges: 
            left = []
            dfs(u, v, left)
            right = []
            dfs(v, u, right)
            for candidates in (left, right):
                total2 = candidates.pop()
                for x in candidates:
                    a, b, c = total^total2, x, total2^x
                    result = min(result, max(a, b, c)-min(a, b, c))
        return result
            

# Time:  O(n^2)
# Space: O(n)
# dfs with stk (slower, sometimes TLE)
class Solution2(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs(nums, adj, u, p):
            result = []
            stk = [(1, (u, p, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    new_ret = []
                    stk.append((2, (u, new_ret, ret)))
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_ret.append([0])
                        stk.append((1, (v, u, new_ret[-1])))
                elif step == 2:
                    u, new_ret, ret = args
                    ret[0] = nums[u]
                    for x in new_ret:
                        ret[0] ^= x[0]
                    result.append(ret[0])
            return result
                
        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        total = reduce(lambda x, y: x^y, nums)
        result = float("inf")
        for u, v in edges: 
            for candidates in (iter_dfs(nums, adj, u, v), iter_dfs(nums, adj, v, u)):
                total2 = candidates.pop()
                for x in candidates:
                    a, b, c = total^total2, x, total2^x
                    result = min(result, max(a, b, c)-min(a, b, c))
        return result
