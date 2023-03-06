# Time:  O(n) 
# Space: O(h)

import collections


# iterative dfs
class Solution(object):
    def rootCount(self, edges, guesses, k):
        """
        :type edges: List[List[int]]
        :type guesses: List[List[int]]
        :type k: int
        :rtype: int
        """
        def iter_dfs():
            result = 0
            stk = [(0, -1)]
            while stk:
                u, p = stk.pop()
                result += int((p, u) in lookup)
                for v in adj[u]:
                    if v == p:
                        continue
                    stk.append((v, u))
            return result
        
        def iter_dfs2(curr):
            result = 0
            stk = [(0, -1, curr)]
            while stk:
                u, p, curr = stk.pop()
                if (p, u) in lookup:
                    curr -= 1
                if (u, p) in lookup:
                    curr += 1
                result += int(curr >= k)
                for v in adj[u]:
                    if v == p:
                        continue
                    stk.append((v, u, curr))
            return result

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = {(u, v) for u, v in guesses}
        curr = iter_dfs()
        return iter_dfs2(curr)


# Time:  O(n) 
# Space: O(h)
import collections


# dfs
class Solution2(object):
    def rootCount(self, edges, guesses, k):
        """
        :type edges: List[List[int]]
        :type guesses: List[List[int]]
        :type k: int
        :rtype: int
        """
        def dfs(u, p):
            cnt = int((p, u) in lookup)
            for v in adj[u]:
                if v == p:
                    continue
                cnt += dfs(v, u)
            return cnt
        
        def dfs2(u, p, curr):
            if (p, u) in lookup:
                curr -= 1
            if (u, p) in lookup:
                curr += 1
            cnt = int(curr >= k)
            for v in adj[u]:
                if v == p:
                    continue
                cnt += dfs2(v, u, curr)
            return cnt

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = {(u, v) for u, v in guesses}
        curr = dfs(0, -1)
        return dfs2(0, -1, curr)


# Time:  O(n) ~ O(n^2), worst case in star tree 
# Space: O(n)
import collections


# memoization
class Solution3(object):
    def rootCount(self, edges, guesses, k):
        """
        :type edges: List[List[int]]
        :type guesses: List[List[int]]
        :type k: int
        :rtype: int
        """
        cnt = [0]
        def memoization(u, p):
            if (u, p) not in memo:
                memo[u, p] = int((p, u) in lookup)
                for v in adj[u]:
                    if v == p:
                        continue
                    cnt[0] += 1
                    memo[u, p] += memoization(v, u)
            return memo[u, p]

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = {(u, v) for u, v in guesses}
        memo = {}
        return sum(memoization(i, -1) >= k for i in adj.iterkeys())
