# Time:  O(o * l + k^3 + n * c * l), o = len(original), l = max(len(x) for x in original), k = len(lookups), c = len({len(x) for x in original})
# Space: O(o * l + k^2 + c + l)

import collections
import itertools


# hash table, Floyd-Warshall algorithm, dp
class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        INF = float("inf")
        def floydWarshall(dist):
            for k in xrange(len(dist)):
                for i in xrange(len(dist)):
                    for j in xrange(len(dist[i])):
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
        
        lookups = collections.defaultdict(dict)
        for x in itertools.chain(original, changed):
            l = len(x)
            lookup = lookups[l]
            if x not in lookup:
                lookup[x] = len(lookup)
        dists = {l:[[0 if u == v else INF for v in xrange(len(lookup))] for u in xrange(len(lookup))] for l, lookup in lookups.iteritems()}
        for i in xrange(len(original)):
            l = len(original[i])
            lookup, dist = lookups[l], dists[l]
            u, v = lookup[original[i]], lookup[changed[i]]
            dist[u][v] = min(dist[u][v], cost[i])
        for dist in dists.itervalues():
            floydWarshall(dist)
        candidates = {len(x) for x in original}
        dp = [INF]*(max(len(x) for x in original)+1)
        dp[0] = 0
        for i in xrange(len(source)):
            if dp[i%len(dp)] == INF:
                continue
            if source[i] == target[i]:
                dp[(i+1)%len(dp)] = min(dp[(i+1)%len(dp)], dp[i%len(dp)])
            for l in candidates:
                if i+l > len(source):
                    continue
                lookup, dist = lookups[l], dists[l]
                u, v = source[i:i+l], target[i:i+l]
                if u in lookup and v in lookup:
                    dp[(i+l)%len(dp)] = min(dp[(i+l)%len(dp)], dp[i%len(dp)]+dist[lookup[u]][lookup[v]])
            dp[i%len(dp)] = INF
        return dp[len(source)%len(dp)] if dp[len(source)%len(dp)] != INF else -1


# Time:  O(o * l + k^3 + n * l), o = len(original), l = max(len(x) for x in original), k = trie.k
# Space: O(t + k^2 + l)
import itertools


# trie, Floyd-Warshall algorithm, dp
class Solution2(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        INF = float("inf")
        class Trie(object):
            def __init__(self):
                self.__nodes = []
                self.__idxs = []
                self.k = 0
                self.__new_node()
            
            def __new_node(self):
                self.__nodes.append([-1]*26)
                self.__idxs.append(-1)
                return len(self.__nodes)-1

            def add(self, s):
                curr = 0
                for c in s:
                    x = ord(c)-ord('a')
                    if self.__nodes[curr][x] == -1:
                        self.__nodes[curr][x] = self.__new_node()
                    curr = self.__nodes[curr][x]
                if self.__idxs[curr] == -1:
                    self.__idxs[curr] = self.k
                    self.k += 1
                return self.__idxs[curr]
            
            def query(self, s):
                curr = 0
                for c in s:
                    curr = self.__nodes[curr][ord(c)-ord('a')]
                return self.__idxs[curr]
    
            def next(self, curr, c):
                return self.__nodes[curr][ord(c)-ord('a')]

            def id(self, curr):
                return self.__idxs[curr]

        def floydWarshall(dist):
            for k in dist.iterkeys():
                for i in dist.iterkeys():
                    for j in dist.iterkeys():
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
        
        trie = Trie()
        buckets = collections.defaultdict(set)
        for x in itertools.chain(original, changed):
            buckets[len(x)].add(trie.add(x))
        dists = {l:{u:{v:0 if u == v else INF for v in lookup} for u in lookup} for l, lookup in buckets.iteritems()}
        for i in xrange(len(original)):
            l = len(original[i])
            dist = dists[l]
            u, v = trie.query(original[i]), trie.query(changed[i])
            dist[u][v] = min(dist[u][v], cost[i])
        for dist in dists.itervalues():
            floydWarshall(dist)
        dp = [INF]*(max(len(x) for x in original)+1)
        dp[0] = 0
        for i in xrange(len(source)):
            if dp[i%len(dp)] == INF:
                continue
            if source[i] == target[i]:
                dp[(i+1)%len(dp)] = min(dp[(i+1)%len(dp)], dp[i%len(dp)])
            u = v = 0
            for j in xrange(i, len(source)):
                u = trie.next(u, source[j])
                v = trie.next(v, target[j])
                if u == -1 or v == -1:
                    break
                if trie.id(u) != -1 and trie.id(v) != -1:
                    dp[(j+1)%len(dp)] = min(dp[(j+1)%len(dp)], dp[i%len(dp)]+dists[j-i+1][trie.id(u)][trie.id(v)])
            dp[i%len(dp)] = INF
        return dp[len(source)%len(dp)] if dp[len(source)%len(dp)] != INF else -1
