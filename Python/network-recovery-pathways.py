# Time:  O((n + e) * logr), r = max(e[2] for e in edges)
# Space: O(n + e)

# binary search, topological sort, dp
class Solution(object):
    def findMaxPathScore(self, edges, online, k):
        """
        :type edges: List[List[int]]
        :type online: List[bool]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def topological_sort():
            in_degree = [0]*len(adj)
            for u in xrange(len(adj)):
                for v, _ in adj[u]:
                    in_degree[v] += 1
            result = []
            q = [u for u in xrange(len(adj)) if not in_degree[u]]
            while q:
                new_q = []
                for u in q:
                    result.append(u)
                    for v, _ in adj[u]:
                        in_degree[v] -= 1
                        if in_degree[v]:
                            continue
                        new_q.append(v)
                q = new_q
            return result

        def check(x):
            dist = [INF]*len(adj)
            dist[0] = 0
            for u in order:
                if dist[u] == INF:
                    continue
                for v, c in adj[u]:
                    if not (c >= x and online[v]):
                        continue
                    dist[v] = min(dist[v], dist[u]+c)
            return dist[-1] <= k

        adj = [[] for _ in xrange(len(online))]
        for u, v, c in edges:
            adj[u].append((v, c))
        order = topological_sort()
        left, right = INF, 0
        for u in xrange(len(adj)):
            for _, c in adj[u]:
                left = min(left, c)
                right = max(right, c)
        result = binary_search_right(left, right, check)
        return result if result >= left else -1
