# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        lookup, graph = set(), collections.defaultdict(list)
        for u, v in connections:
            lookup.add(u*n+v)
            graph[v].append(u)
            graph[u].append(v) 
        result = 0
        stk = [(-1, 0)]
        while stk:
            parent, u = stk.pop()
            result += (parent*n+u in lookup)
            for v in reversed(graph[u]):
                if v == parent:
                    continue
                stk.append((u, v))
        return result


# Time:  O(n)
# Space: O(n)
import collections


class Solution2(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        def dfs(n, lookup, graph, parent, u):
            result = (parent*n+u in lookup)
            for v in graph[u]:
                if v == parent:
                    continue
                result += dfs(n, lookup, graph, u, v)  
            return result

        lookup, graph = set(), collections.defaultdict(list)
        for u, v in connections:
            lookup.add(u*n+v)
            graph[v].append(u)
            graph[u].append(v) 
        return dfs(n, lookup, graph, -1, 0)
