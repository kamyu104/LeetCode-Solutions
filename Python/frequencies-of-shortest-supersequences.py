# Time:  O(n + k^2 * 2^k), k = len(indegree) <= 16
# Space: O(k^2)

import collections


# bitmasks, topological sort
class Solution(object):
    def supersequences(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def f(x):
            x = ord(x)-ord('a')
            if char_to_int[x] == -1:
                int_to_char[len(indegree)] = x
                char_to_int[x] = len(indegree)
                indegree.append(0)
            return char_to_int[x]
                
        def topological_sort(cnt):
            total = sum(cnt)
            if total > ans[0]:
                return
            new_cnt = cnt[:]
            new_indgree = indegree[:]
            lookup = [False]*len(cnt)
            q = []
            for u in xrange(len(indegree)):
                if not new_indgree[u] or new_cnt[u] == 2:
                    new_cnt[u] -= 1
                    lookup[u] = True
                    q.append(u)
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        new_indgree[v] -= 1
                        if new_indgree[v]:
                            continue
                        new_cnt[v] -= 1
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q
            if any(new_cnt):
                return
            if total < ans[0]:
                ans[0] = total
                ans[1][:] = []
            ans[1].append(cnt)

        adj = [[] for _ in xrange(26)]
        char_to_int, int_to_char, indegree = [-1]*26, [0]*26, []
        for w in words:
            adj[f(w[0])].append(f(w[1]))
            indegree[f(w[1])] += 1
        ans = [float("inf"), []]
        for mask in xrange(1<<len(indegree)):
            topological_sort([2 if mask&(1<<i) else 1 for i in xrange(len(indegree))])
        result = []
        for cnt in ans[1]:
            new_cnt = [0]*26
            for i, x in enumerate(cnt):
                new_cnt[int_to_char[i]] = x
            result.append(new_cnt)
        return result
