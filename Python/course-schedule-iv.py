# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def checkIfPrerequisite(self, n, prerequisites, queries):
        """
        :type n: int
        :type prerequisites: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        def floydWarshall(n, graph): 
            reachable = set(map(lambda x: x[0]*n+x[1], graph)) 
            for k in xrange(n): 
                for i in xrange(n): 
                    for j in xrange(n): 
                        if i*n+j not in reachable and (i*n+k in reachable and k*n+j in reachable):
                            reachable.add(i*n+j)
            return reachable

        reachable = floydWarshall(n, prerequisites)
        return [i*n+j in reachable for i, j in queries]


# Time:  O(n * q)
# Space: O(p + n)
import collections


class Solution2(object):
    def checkIfPrerequisite(self, n, prerequisites, queries):
        """
        :type n: int
        :type prerequisites: List[List[int]]
        :type queries: List[List[int]]
        :rtyp
        """
        graph = collections.defaultdict(list)
        for u, v in prerequisites:
            graph[u].append(v)
        result = []
        for i, j in queries:
            stk, lookup = [i], set([i])
            while stk:
                node = stk.pop()
                for nei in graph[node]:
                    if nei in lookup:
                        continue
                    stk.append(nei)
                    lookup.add(nei)
            result.append(j in lookup)
        return result
