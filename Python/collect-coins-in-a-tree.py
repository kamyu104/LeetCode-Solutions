# Time:  O(n)
# Space: O(n)

# tree, bfs
class Solution(object):
    def collectTheCoins(self, coins, edges):
        """
        :type coins: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        DISTANCE = 2

        adj = [set() for _ in xrange(len(coins))]
        for u, v in edges:
            adj[u].add(v)
            adj[v].add(u)
        n = len(coins)
        q = []
        for u in xrange(len(coins)):
            while len(adj[u]) == 1 and not coins[u]:
                v = adj[u].pop()
                adj[v].remove(u)
                n -= 1
                u = v
        q = [u for u in xrange(len(coins)) if len(adj[u]) == 1]
        for _ in xrange(DISTANCE):
            new_q = []
            for u in q:
                if not adj[u]:
                    assert(n == 1)
                    break
                v = adj[u].pop()
                adj[v].remove(u)
                n -= 1
                if len(adj[v]) == 1:
                    new_q.append(v)
            q = new_q
        return (n-1)*2
