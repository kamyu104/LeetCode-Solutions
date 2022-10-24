# Time:  O(q + n)
# Space: O(n)

import collections


# bfs
class Solution(object):
    def numberOfNodes(self, n, queries):
        """
        :type n: int
        :type queries: List[int]
        :rtype: int
        """
        def bfs():
            result = 0
            q = [(1, 0)]
            while q:
                new_q = []
                for u, curr in q:
                    curr ^= cnt[u]%2
                    result += curr
                    for v in xrange(2*u, min(2*u+1, n)+1):
                        q.append((v, curr))
                q = new_q
            return result

        cnt = collections.Counter(queries)
        return bfs()


# Time:  O(q + n)
# Space: O(q + logn)
import collections


# iterative dfs
class Solution2(object):
    def numberOfNodes(self, n, queries):
        """
        :type n: int
        :type queries: List[int]
        :rtype: int
        """
        def iter_dfs():
            result = 0
            stk = [(1, 0)]
            while stk:
                u, curr = stk.pop()
                curr ^= cnt[u]%2
                result += curr
                for v in reversed(xrange(2*u, min(2*u+1, n)+1)):
                    stk.append((v, curr))
            return result

        cnt = collections.Counter(queries)
        return iter_dfs()


# Time:  O(q + n)
# Space: O(q + logn)
import collections


# dfs
class Solution3(object):
    def numberOfNodes(self, n, queries):
        """
        :type n: int
        :type queries: List[int]
        :rtype: int
        """
        def dfs(u, curr):
            curr ^= cnt[u]%2
            return curr+sum(dfs(v, curr) for v in xrange(2*u, min(2*u+1, n)+1))
    
        cnt = collections.Counter(queries)
        return dfs(1, 0)
