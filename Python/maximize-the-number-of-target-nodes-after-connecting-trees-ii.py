# Time:  O(n + m)
# Space: O(n + m)

# bfs
class Solution(object):
    def maxTargetNodes(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: List[int]
        """
        def bfs(adj):
            result = [0]*len(adj)
            parity = 0
            lookup = [-1]*len(adj)
            lookup[0] = parity
            q = [0]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v] != -1:
                            continue
                        lookup[v] = parity^1
                        new_q.append(v)
                q = new_q
                parity ^= 1
            cnt = sum(lookup)
            return [cnt if lookup[u] else len(adj)-cnt for u in xrange(len(adj))]
    
        def find_adj(edges):
            adj = [[] for _ in xrange(len(edges)+1)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj

        adj2 = find_adj(edges2)
        mx = max(bfs(adj2))
        adj1 = find_adj(edges1)
        return [mx+x for x in bfs(adj1)]
