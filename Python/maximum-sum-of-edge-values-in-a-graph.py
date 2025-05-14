# Time:  O(n)
# Space: O(n)

# flood fill, bfs, counting sort, greedy
"""
n = 11
edges = [[0,1],[1,2],[2,3],[5,6],[6,7]]
max is 367 but ans is 366, which is wrong by greedy
"""
class Solution_WA(object):
    def maxScore(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def bfs(u):
            lookup[u] = True
            result = [u]
            for u in result:
                for v in adj[u]:
                    if lookup[v]:
                        continue
                    lookup[v] = True
                    result.append(v)
            return result

        def f(l, r, is_cycle):
            a = b = r
            result = 0
            for c in reversed(xrange(l, r)):
                result += a*c
                a, b = b, c
            if is_cycle:
                result += a*b
            return result

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        cycles, chains = [], []
        lookup = [False]*n
        for u in xrange(n):
            if lookup[u]:
                continue
            comp = bfs(u)
            if all(len(adj[x]) == 2 for x in comp):
                cycles.append(len(comp))
            else:
                chains.append(len(comp))
        result = 0
        for l in cycles:
            result += f(n-l+1, n, True)
            n -= l
        cnt = [0]*((max(chains) if chains else 0)+1)
        for l in chains:
            cnt[l] += 1
        for l in reversed(xrange(len(cnt))):
            for _ in xrange(cnt[l]):
                result += f(n-l+1, n, False)
                n -= l
        return result
