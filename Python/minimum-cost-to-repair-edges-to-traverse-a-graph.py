# Time:  O((n + m) * logr)
# Space: O(n + m)

# binary search, bfs
class Solution(object):
    def minCost(self, n, edges, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left
        
        def bfs(x):
            lookup = [False]*len(adj)
            lookup[0] = True
            q = [0]
            d = 0
            while q:
                if d == k+1:
                    break
                new_q = []
                for u in q:
                    if u == n-1:
                        return True
                    for v, w in adj[u]:
                        if w > x or lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
                d += 1
            return False
            
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        left = min(w for _, _, w in edges)
        right = max(w for _, _, w in edges)
        result = binary_search(left, right, bfs)
        return result if result != right+1 else -1
