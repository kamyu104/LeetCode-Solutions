# Time:  O(n + e + q)
# Space: O(n + e)

import collections
import itertools


# pure counting solution
class Solution(object):
    def countPairs(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        degree = [0]*(n+1)
        shared = collections.Counter((min(n1, n2), max(n1, n2)) for n1, n2 in edges)
        for u, v in edges:
            degree[u] += 1
            degree[v] += 1
        cnt = [0]*(2*(max(degree[1:])+1))
        count = collections.Counter(degree[1:])
        for i, j in itertools.product(count, count):  # Time: O(d^2) = O(e)
            if i < j:
                cnt[i+j] += count[i]*count[j]
            elif i == j:
                cnt[i+j] += count[i]*(count[i]-1)//2
        for (i, j), shared_degree in shared.iteritems():
            cnt[degree[i]+degree[j]] -= 1
            cnt[degree[i]+degree[j]-shared_degree] += 1
        for i in reversed(xrange(len(cnt)-1)):  # accumulate
            cnt[i] += cnt[i+1]
        return [cnt[q+1] if q+1 < len(cnt) else 0 for q in queries]


# Time:  O(nlogn + q * (n + e))
# Space: O(n + e)
import collections


# two pointers solution
class Solution2(object):
    def countPairs(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        degree = [0]*(n+1)
        shared = collections.Counter((min(n1, n2), max(n1, n2)) for n1, n2 in edges)
        for n1, n2 in edges:
            degree[n1] += 1
            degree[n2] += 1
        sorted_degree = sorted(degree)
        result = []
        for k, q in enumerate(queries):
            left, right = 1, n
            cnt = 0
            while left < right:
                if q < sorted_degree[left]+sorted_degree[right]:
                    cnt += right-left
                    right -= 1
                else:
                    left += 1
            for (i, j), shared_degree in shared.iteritems():
                if degree[i]+degree[j]-shared_degree <= q < degree[i]+degree[j]:
                    cnt -= 1
            result.append(cnt)
        return result
