# Time:  O(n^2)
# Space: O(n)

# Bellman-Ford Algorithm
class Solution(object):
    def maxAmount(self, initialCurrency, pairs1, rates1, pairs2, rates2):
        """
        :type initialCurrency: str
        :type pairs1: List[List[str]]
        :type rates1: List[float]
        :type pairs2: List[List[str]]
        :type rates2: List[float]
        :rtype: float
        """
        def BellmanFord(dist, pairs, rates):
            for _ in xrange(len(pairs)):
                for i in xrange(len(pairs)):
                    dist[pairs[i][1]] = max(dist[pairs[i][1]], dist[pairs[i][0]]*rates[i])
                    dist[pairs[i][0]] = max(dist[pairs[i][0]], dist[pairs[i][1]]*(1/rates[i]))
        
        dist = collections.defaultdict(int)
        dist[initialCurrency] = 1.0
        BellmanFord(dist, pairs1, rates1)
        BellmanFord(dist, pairs2, rates2)
        return dist[initialCurrency]
                

# Time:  O(n^2)
# Space: O(n)
import collections


# bfs
class Solution2(object):
    def maxAmount(self, initialCurrency, pairs1, rates1, pairs2, rates2):
        """
        :type initialCurrency: str
        :type pairs1: List[List[str]]
        :type rates1: List[float]
        :type pairs2: List[List[str]]
        :type rates2: List[float]
        :rtype: float
        """
        def find_adj(pairs, rates):
            adj = collections.defaultdict(list)
            for i in xrange(len(pairs)):
                adj[pairs[i][0]].append((pairs[i][1], rates[i]))
                adj[pairs[i][1]].append((pairs[i][0], 1/rates[i]))
            return adj

        def bfs(dist, adj):
            q = dist.keys()
            while q:
                new_q = []
                for u in q:
                    for v, w in adj[u]:
                        if not w*dist[u] > dist[v]:
                            continue
                        dist[v] = w*dist[u]
                        new_q.append(v)
                q = new_q
            return dist
    
        dist = collections.defaultdict(int)
        dist[initialCurrency] = 1.0
        adj1 = find_adj(pairs1, rates1)
        bfs(dist, adj1)  # Time: O(n)
        adj2 = find_adj(pairs2, rates2)
        bfs(dist, adj2)  # Time: O(n^2)
        return dist[initialCurrency]
