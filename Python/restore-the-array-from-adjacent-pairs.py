# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def restoreArray(self, adjacentPairs):
        """
        :type adjacentPairs: List[List[int]]
        :rtype: List[int]
        """
        adj = collections.defaultdict(list)
        for u, v in adjacentPairs: 
            adj[u].append(v)
            adj[v].append(u)
        result = next([x, adj[x][0]] for x in adj if len(adj[x]) == 1)
        while len(result) != len(adjacentPairs)+1:
            result.append(adj[result[-1]][adj[result[-1]][0] == result[-2]])
        return result
