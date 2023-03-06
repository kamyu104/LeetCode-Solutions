# Time:  O(n) 
# Space: O(n)

import collections


# dfs
class Solution(object):
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
        parents = {}
        curr = dfs(0, -1)
        return dfs2(0, -1, curr)


# Time:  O(n) ~ O(n^2), worst case in star tree 
# Space: O(n)
import collections


# memoization
class Solution2(object):
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
