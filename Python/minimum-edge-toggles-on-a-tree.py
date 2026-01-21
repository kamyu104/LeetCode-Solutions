# Time:  O(n)
# Space: O(n)

# greedy, topological sort
class Solution(object):
    def minimumFlips(self, n, edges, start, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type start: str
        :type target: str
        :rtype: List[int]
        """
        diff = [1 if start[u] != target[u] else 0 for u in xrange(n)]
        if sum(diff)%2:
            return [-1]
        degree = [0]*n
        adj = [0]*n
        edge = [0]*n
        for idx, (u, v) in enumerate(edges):
            degree[u] += 1
            degree[v] += 1
            adj[u] ^= v
            adj[v] ^= u
            edge[u] ^= idx
            edge[v] ^= idx
        lookup = [False]*len(edges)
        for u in xrange(n):
            while degree[u] == 1:
                v, idx = adj[u], edge[u]
                degree[u] -= 1
                degree[v] -= 1
                adj[u] ^= v
                adj[v] ^= u
                edge[u] ^= idx
                edge[v] ^= idx
                if diff[u]:
                    diff[u] ^= 1
                    diff[v] ^= 1
                    lookup[idx] = True
                u = v
        return [i for i in xrange(len(lookup)) if lookup[i]]
