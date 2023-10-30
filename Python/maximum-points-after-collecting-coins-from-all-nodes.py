# Time:  O(nlogr), r = max(coins)
# Space: O(n)

# dfs, bitmasks, pruning
class Solution(object):
    def maximumPoints(self, edges, coins, k):
        """
        :type edges: List[List[int]]
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        NEG_INF = float("-inf")
        def dfs(u, p, base):
            if base >= max_base:
                return 0
            if lookup[u]&base:  # we prefer the first way to the second way, so the visited state cannot improve the current chosen ways
                return NEG_INF
            lookup[u] |= base
            return max(((coins[u]//base)-k)+sum(dfs(v, u, base) for v in adj[u] if v != p),
                        (coins[u]//(base<<1))+sum(dfs(v, u, base<<1) for v in adj[u] if v != p) if (coins[u]//base)-k < coins[u]//(base*2) else NEG_INF)  #  if (coins[u]//base)-k >= coins[u]//(base*2), the first way is always better

        adj = [[] for _ in xrange(len(coins))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        max_base = 1<<max(coins).bit_length()
        lookup = [0]*len(coins)
        return dfs(0, -1, 1)


# Time:  O(nlogr), r = max(coins)
# Space: O(nlogr)
# tree dp, memoization
class Solution2(object):
    def maximumPoints(self, edges, coins, k):
        """
        :type edges: List[List[int]]
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        def memoization(u, p, d):
            if d >= max_d:
                return 0
            if lookup[u][d] is None:
                lookup[u][d] = max(((coins[u]>>d)-k)+sum(memoization(v, u, d) for v in adj[u] if v != p),
                                    (coins[u]>>(d+1))+sum(memoization(v, u, d+1) for v in adj[u] if v != p))
            return lookup[u][d]

        adj = [[] for _ in xrange(len(coins))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        max_d = max(coins).bit_length()
        lookup = [[None]*max_d for _ in xrange(len(coins))]
        return memoization(0, -1, 0)
