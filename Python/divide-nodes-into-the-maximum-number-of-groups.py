# Time:  O(n^2)
# Space: O(n)

# iterative dfs, bfs
class Solution(object):
    def magnificentSets(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs(u):
            group = [u]
            stk = [u]
            lookup[u] += 1
            while stk:
                u = stk.pop()
                for v in adj[u]:
                    if lookup[v]:
                        if lookup[v]%2 == lookup[u]%2:  # odd-length cycle
                            return []
                        continue
                    lookup[v] = lookup[u]+1
                    group.append(v)
                    stk.append(v)
            return group

        def bfs(u):
            result = 0
            lookup = [False]*n
            q = [u]
            lookup[u] = True
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
                result += 1
            return result
    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        result = 0
        lookup = [0]*n
        for u in xrange(n):
            if lookup[u]:
                continue
            group = iter_dfs(u)
            if not group:
                return -1
            result += max(bfs(x) for x in group)
        return result
