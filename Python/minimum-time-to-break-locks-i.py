# Time:  O(n^3)
# Space: O(n^2)

# hungarian algorithm, weighted bipartite matching
class Solution(object):
    def findMinimumTime(self, strength, K):
        """
        :type strength: List[int]
        :type K: int
        :rtype: int
        """
        # Template translated from:
        # https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/WeightedMatching.h
        def hungarian(a):  # Time: O(n^2 * m), Space: O(n + m)
            if not a:
                return 0, []
            n, m = len(a)+1, len(a[0])+1
            u, v, p, ans = [0]*n, [0]*m, [0]*m, [0]*(n-1)
            for i in xrange(1, n):
                p[0] = i
                j0 = 0  # add "dummy" worker 0
                dist, pre = [float("inf")]*m, [-1]*m
                done = [False]*(m+1)
                while True:  # dijkstra
                    done[j0] = True
                    i0, j1, delta = p[j0], None, float("inf")
                    for j in xrange(1, m):
                        if done[j]:
                            continue
                        cur = a[i0-1][j-1]-u[i0]-v[j]
                        if cur < dist[j]:
                            dist[j], pre[j] = cur, j0
                        if dist[j] < delta:
                            delta, j1 = dist[j], j
                    for j in xrange(m):
                        if done[j]:
                            u[p[j]] += delta
                            v[j] -= delta
                        else:
                            dist[j] -= delta
                    j0 = j1
                    if not p[j0]:
                        break
                while j0:  # update alternating path
                    j1 = pre[j0]
                    p[j0], j0 = p[j1], j1
            for j in xrange(1, m):
                if p[j]:
                    ans[p[j]-1] = j-1
            return -v[0], ans  # min cost

        def ceil_divide(a, b):
            return (a+b-1)//b
    
        adj = [[ceil_divide(strength[i], 1+j*K) for j in xrange(len(strength))] for i in xrange(len(strength))]
        return hungarian(adj)[0]


# Time:  O(n ^ 2^n)
# Space: O(2^n)
# bitmasks, dp
class Solution2(object):
    def findMinimumTime(self, strength, K):
        """
        :type strength: List[int]
        :type K: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
    
        def popcount(x):
            return bin(x).count('1')
    
        dp = [float('inf')]*(1<<len(strength))
        dp[0] = 0
        for mask in xrange(1, len(dp)):
            x = 1+(popcount(mask)-1)*K
            for i in xrange(len(strength)):
                if not (mask&(1<<i)):
                    continue
                dp[mask] = min(dp[mask], dp[mask^(1<<i)]+ceil_divide(strength[i], x))
        return dp[-1]
