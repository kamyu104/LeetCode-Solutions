# Time:  O(n^2)
# Space: O(n)

# dfs with stack
class Solution(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def is_ancestor(a, b):
            return left[a] <= left[b] and right[b] <= right[a]

        def iter_dfs():
            cnt = 0
            left = [0]*len(nums)
            right = [0]*len(nums)
            stk = [(1, (0, -1))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p = args
                    left[u] = cnt
                    cnt += 1
                    stk.append((2, (u, p)))
                    for v in adj[u]:
                        if v == p:
                            continue
                        stk.append((1, (v, u)))
                elif step == 2:
                    u, p = args
                    for v in adj[u]:
                        if v == p:
                            continue
                        nums[u] ^= nums[v]
                    right[u] = cnt
            return left, right
                
        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        left, right = iter_dfs()
        result = float("inf")
        for i in xrange(1, len(nums)):
            for j in xrange(i+1, len(nums)):
                if is_ancestor(i, j):
                    a, b, c = nums[0]^nums[i], nums[i]^nums[j], nums[j]
                elif is_ancestor(j, i):
                    a, b, c = nums[0]^nums[j], nums[j]^nums[i], nums[i]
                else:
                    a, b, c = nums[0]^nums[i]^nums[j], nums[i], nums[j]
                result = min(result, max(a, b, c)-min(a, b, c))
        return result


# Time:  O(n^2)
# Space: O(n)
# dfs with recursion
class Solution2(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        def is_ancestor(a, b):
            return left[a] <= left[b] and right[b] <= right[a]

        def dfs(u, p):
            left[u] = cnt[0]
            cnt[0] += 1
            for v in adj[u]:
                if v == p:
                    continue
                dfs(v, u)
                nums[u] ^= nums[v]
            right[u] = cnt[0]
                
        adj = [[] for _ in xrange(len(nums))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        cnt = [0]
        left = [0]*len(nums)
        right = [0]*len(nums)
        dfs(0, -1)
        result = float("inf")
        for i in xrange(1, len(nums)):
            for j in xrange(i+1, len(nums)):
                if is_ancestor(i, j):
                    a, b, c = nums[0]^nums[i], nums[i]^nums[j], nums[j]
                elif is_ancestor(j, i):
                    a, b, c = nums[0]^nums[j], nums[j]^nums[i], nums[i]
                else:
                    a, b, c = nums[0]^nums[i]^nums[j], nums[i], nums[j]
                result = min(result, max(a, b, c)-min(a, b, c))
        return result
            

# Time:  O(n^2)
# Space: O(n)
# dfs with recursion
class Solution3(object):
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
class Solution4(object):
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
                    new_rets = []
                    stk.append((2, (u, new_rets, ret)))
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_rets.append([0])
                        stk.append((1, (v, u, new_rets[-1])))
                elif step == 2:
                    u, new_rets, ret = args
                    ret[0] = nums[u]
                    for x in new_rets:
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
