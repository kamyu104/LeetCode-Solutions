# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """        
        def dfs(G, node, t, target, parent):
            if not (len(G[node])-(parent != 0)) or not t:
                return float(node == target)
            result = sum(dfs(G, child, t-1, target, node)
                         for child in G[node] if child != parent)
            return result/(len(G[node])-(parent != 0))
        
        G = collections.defaultdict(list)
        for u, v in edges:
            G[u].append(v)
            G[v].append(u)
        return dfs(G, 1, t, target, 0)
