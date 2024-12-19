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
                    dist[pairs[i][0]] = max(dist[pairs[i][0]], dist[pairs[i][1]]*(1.0/rates[i]))
        
        dist = collections.defaultdict(int)
        dist[initialCurrency] = 1.0
        BellmanFord(dist, pairs1, rates1)
        BellmanFord(dist, pairs2, rates2)
        return dist[initialCurrency]
