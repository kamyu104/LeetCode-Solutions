# Time:  O(|V| * |E|)
# Space: O(|V| + |E|)

# dfs
class Solution(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        def iter_dfs(adj, i, result):
            lookup = [False]*len(adj)
            stk = [i]
            while stk:
                u = stk.pop()
                for v in reversed(adj[u]):
                    if lookup[v]:
                        continue
                    lookup[v] = True
                    stk.append(v)
                    result[v].append(i)
                    
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
        result = [[] for _ in xrange(n)]
        for u in xrange(n):
            iter_dfs(adj, u, result)
        return result


# Time:  O(|V| * |E| * log(|V| * |E|))
# Space: O(|V| + |E|)
# bfs
class Solution2(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        def bfs(adj, i, result):
            lookup = [False]*len(adj)
            q = [i]
            lookup[i] = True
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                        result[i].append(v)
                q = new_q
            result[i].sort()

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[v].append(u)
        result = [[] for _ in xrange(n)]
        for u in xrange(n):
            bfs(adj, u, result) 
        return result


# Time:  O(|V| * |E| * log(|V| * |E|))
# Space: O(|V| + |E|)
# topological sort
class Solution3(object):
    def getAncestors(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        result = [set() for _ in xrange(n)]
        in_degree = [0]*n
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            in_degree[v] += 1
            result[v].add(u)
        q = [u for u, d in enumerate(in_degree) if not d]
        while q:
            new_q = []
            for u in q:
                for v in adj[u]:
                    result[v].update(result[u])
                    in_degree[v] -= 1
                    if not in_degree[v]:
                        new_q.append(v)
            q = new_q
        return [sorted(s) for s in result]
