# Time:  O(n^4 * 2^n)
# Space: O(n + e)

# bitmasks, dp, freq table
class Solution(object):
    def maxLen(self, n, edges, label):
        """
        :type n: int
        :type edges: List[List[int]]
        :type label: str
        :rtype: int
        """
        def popcount(x):
            return bin(x).count('1')

        if len(edges) == n*(n-1)//2:  # to improve performance
            cnt = [0]*26
            for x in label:
                cnt[ord(x)-ord('a')] += 1
            return 2*sum(c//2 for c in cnt)+1*any(c%2 for c in cnt)

        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        dp = [[[False]*n for _ in xrange(n)]for _ in xrange(1<<n)]
        for u in xrange(n):
            dp[1<<u][u][u] = True
        for u, v in edges:
            if label[u] == label[v]:
                dp[(1<<u)|(1<<v)][min(u, v)][max(u, v)] = True
        result = 0
        for mask in xrange(1, 1<<n):
            for u in xrange(n):
                for v in xrange(u, n):
                    if not dp[mask][u][v]:
                        continue
                    result = max(result, popcount(mask))
                    for nu in adj[u]:
                        if mask&(1<<nu):
                            continue
                        for nv in adj[v]:
                            if mask&(1<<nv):
                                continue
                            if nu == nv:
                                continue
                            if label[nu] == label[nv]:
                                dp[mask|(1<<nu)|(1<<nv)][min(nu, nv)][max(nu, nv)] = True
        return result
