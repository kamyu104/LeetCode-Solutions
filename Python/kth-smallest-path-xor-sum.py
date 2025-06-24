# Time:  O(n * (logn)^2 + qlogn)
# Space: O(n + q)

from sortedcontainers import SortedList


# iterative dfs, small-to-large merging, sorted list
class Solution(object):
    def kthSmallest(self, par, vals, queries):
        """
        :type par: List[int]
        :type vals: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def small_to_large_merge(sl1, sl2):  # Total Time: O(n * (logn)^2)
            if len(sl1) < len(sl2):
                sl1, sl2 = sl2, sl1
            for x in sl2:  # each node is merged at most O(logn) times
                if x not in sl1:
                    sl1.add(x)  # each add costs O(logn)
            return sl1

        def iter_dfs():
            sl = [SortedList() for _ in xrange(len(adj))]
            result = [-1]*len(queries)
            stk = [(1, (0, 0))]
            while stk:
                step, (u, curr) = stk.pop()
                if step == 1:
                    curr ^= vals[u]
                    sl[u].add(curr)
                    stk.append((2, (u, curr)))
                    for v in reversed(adj[u]):
                        stk.append((1, (v, curr)))
                elif step == 2:
                    for v in adj[u]:
                        sl[u] = small_to_large_merge(sl[u], sl[v])
                    for i in lookup[u]:  # Total Time: O(qlogn)
                        if queries[i][1]-1 < len(sl[u]):
                            result[i] = sl[u][queries[i][1]-1]
            return result

        adj = [[] for _ in xrange(len(par))]
        for u, p in enumerate(par):
            if p != -1:
                adj[p].append(u)
        lookup = [[] for _ in xrange(len(adj))]
        for i, (u, _) in enumerate(queries):
            lookup[u].append(i)
        return iter_dfs()


# Time:  O(n * (logn)^2 + qlogn)
# Space: O(n + q)
from sortedcontainers import SortedList


# dfs, small-to-large merging, sorted list
class Solution2(object):
    def kthSmallest(self, par, vals, queries):
        """
        :type par: List[int]
        :type vals: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def small_to_large_merge(sl1, sl2):  # Total Time: O(n * (logn)^2)
            if len(sl1) < len(sl2):
                sl1, sl2 = sl2, sl1
            for x in sl2:  # each node is merged at most O(logn) times
                if x not in sl1:
                    sl1.add(x)  # each add costs O(logn)
            return sl1

        def dfs(u, curr):
            curr ^= vals[u]
            sl = SortedList([curr])
            for v in adj[u]:
                sl = small_to_large_merge(sl, dfs(v, curr))
            for i in lookup[u]:  # Total Time: O(qlogn)
                if queries[i][1]-1 < len(sl):
                    result[i] = sl[queries[i][1]-1]
            return sl

        adj = [[] for _ in xrange(len(par))]
        for u, p in enumerate(par):
            if p != -1:
                adj[p].append(u)
        lookup = [[] for _ in xrange(len(adj))]
        for i, (u, _) in enumerate(queries):
            lookup[u].append(i)
        result = [-1]*len(queries)
        dfs(0, 0)
        return result
