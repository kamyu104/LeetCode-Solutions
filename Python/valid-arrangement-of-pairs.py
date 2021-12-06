# Time:  O(|V| + |E|)
# Space: O(|V| + |E|)

import collections


# Hierholzer Algorithm
class Solution(object):
    def validArrangement(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: List[List[int]]
        """
        adj = collections.defaultdict(list)
        degree = collections.defaultdict(int)
        for u, v in pairs: 
            adj[u].append(v)
            degree[u] += 1
            degree[v] -= 1       
        result = []
        stk = [next((u for u, c in degree.iteritems() if c == 1), next(degree.iterkeys()))]
        while stk:
            while adj[stk[-1]]: 
                stk.append(adj[stk[-1]].pop())
            result.append(stk.pop())
        result.reverse()
        return [[result[i], result[i+1]] for i in xrange(len(result)-1)]
