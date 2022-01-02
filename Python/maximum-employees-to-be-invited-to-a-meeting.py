# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maximumInvitations(self, favorite):
        """
        :type favorite: List[int]
        :rtype: int
        """
        def find_cycles(adj):
            result = []
            lookup = [False]*len(adj)
            for u in xrange(len(adj)):
                cnt = {}
                while not lookup[u]:
                    lookup[u] = True
                    cnt[u] = len(cnt)
                    u = adj[u]
                if u in cnt:
                    result.append((u, len(cnt)-cnt[u]))
            return result

        def bfs(adj, u, exclude):
            result = 0
            q = [u]
            while q:
                result += 1
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if v == exclude:
                            continue
                        new_q.append(v)
                q = new_q
            return result
            
        inv_adj = [[] for _ in xrange(len(favorite))]  
        for u, v in enumerate(favorite):
            inv_adj[v].append(u)
        cycles = find_cycles(favorite)
        return max(max([l for _, l in cycles if l > 2] or [0]),
                   sum(bfs(inv_adj, u, favorite[u]) + bfs(inv_adj, favorite[u], u) for u, l in cycles if l == 2))
