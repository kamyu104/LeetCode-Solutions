# Time:  O(|V| + |E|)
# Space: O(|E|)

class Solution(object):
    def minimumTime(self, n, relations, time):
        """
        :type n: int
        :type relations: List[List[int]]
        :type time: List[int]
        :rtype: int
        """
        adj = [[] for _ in xrange(n)]
        in_degree = [0]*n
        for prev, nxt in relations:
            adj[prev-1].append(nxt-1)
            in_degree[nxt-1] += 1
        q = [u for u in xrange(n) if not in_degree[u]]
        dist = [time[u] if not in_degree[u] else 0 for u in xrange(n)] 
        while q:
            new_q = []
            for u in q:
                for v in adj[u]:
                    dist[v] = max(dist[v], dist[u]+time[v])
                    in_degree[v] -= 1
                    if not in_degree[v]:
                        new_q.append(v)
            q = new_q
        return max(dist)
