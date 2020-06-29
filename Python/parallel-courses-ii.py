# Time:  O((n * C(c, min(c, k))) * 2^n)
# Space: O(2^n)

import itertools


class Solution(object):
    def minNumberOfSemesters(self, n, dependencies, k):
        """
        :type n: int
        :type dependencies: List[List[int]]
        :type k: int
        :rtype: int
        """
        reqs = [0]*n
        for u, v in dependencies:
            reqs[v-1] |= 1 << (u-1)
        dp = [n]*(1<<n)
        dp[0] = 0
        for mask in xrange(1<<n):
            candidates = []
            for v in xrange(n):
                if (mask&(1<<v)) == 0 and (mask&reqs[v]) == reqs[v]:
                    candidates.append(v)
            for choice in itertools.combinations(candidates, min(len(candidates), k)):
                new_mask = mask
                for v in choice:
                    new_mask |= 1<<v
                dp[new_mask] = min(dp[new_mask], dp[mask]+1)
        return dp[-1]


# Time:  O(nlogn + e), e is the number of edges in graph
# Space: O(n + e)
import collections
import heapq

# wrong greedy solution
# since the priority of courses are hard to decide especially for those courses with zero indegrees are of the same outdegrees and depths
# e.x.
# 9
# [[1,4],[1,5],[3,5],[3,6],[2,6],[2,7],[8,4],[8,5],[9,6],[9,7]]
# 3
class Solution_WA(object):
    def minNumberOfSemesters(self, n, dependencies, k):
        """
        :type n: int
        :type dependencies: List[List[int]]
        :type k: int
        :rtype: int
        """
        def dfs(graph, i, depths):
            if depths[i] == -1:
                depths[i] = max(dfs(graph, child, depths) for child in graph[i])+1 if i in graph else 1
            return depths[i]
            
        degrees = [0]*n
        graph = collections.defaultdict(list)
        for u, v in dependencies:
            graph[u-1].append(v-1)
            degrees[v-1] += 1
        depths = [-1]*n
        for i in xrange(n):
            dfs(graph, i, depths)
        max_heap = []
        for i in xrange(n):
            if not degrees[i]:
                heapq.heappush(max_heap, (-depths[i], i))
        result = 0
        while max_heap:
            new_q = []
            for _ in xrange(min(len(max_heap), k)):
                _, node = heapq.heappop(max_heap)
                if node not in graph:
                    continue
                for child in graph[node]:
                    degrees[child] -= 1
                    if not degrees[child]:
                        new_q.append(child)
            result += 1
            for node in new_q:
                heapq.heappush(max_heap, (-depths[node], node))
        return result
