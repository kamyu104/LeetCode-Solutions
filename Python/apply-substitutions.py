# Time:  O(r * 2^r)
# Space: O(r * 2^r)

import collections


# topological sort
class Solution(object):
    def applySubstitutions(self, replacements, text):
        """
        :type replacements: List[List[str]]
        :type text: str
        :rtype: str
        """
        def find_adj(s):
            result = set()
            i = 0
            while i < len(s):
                if s[i] != '%':
                    i += 1
                    continue
                j = next(j for j in xrange(i+1, len(s)) if s[j] == '%')
                result.add(s[i+1:j])
                i = j+1
            return result
        
        def replace(s):
            result = []
            i = 0
            while i < len(s):
                if s[i] != '%':
                    result.append(s[i])
                    i += 1
                    continue
                j = next(j for j in xrange(i+1, len(s)) if s[j] == '%')
                result.append(lookup[s[i+1:j]])
                i = j+1
            return "".join(result)
        
        def topological_sort():
            adj = collections.defaultdict(set)
            in_degree = collections.defaultdict(int)
            for u, s in replacements:
                for v in find_adj(s):
                    adj[v].add(u)
                    in_degree[u] += 1
            result = []
            q = [u for u, _ in replacements if not in_degree[u]]
            while q:
                new_q = []
                for u in q:
                    lookup[u] = replace(lookup[u])
                    for v in adj[u]:
                        in_degree[v] -= 1
                        if in_degree[v]:
                            continue
                        new_q.append(v)
                q = new_q
            return result

        lookup = {k:v for k, v in replacements}
        topological_sort()
        return replace(text)


# Time:  O(r * 2^r)
# Space: O(r * 2^r)
# memoization
class Solution2(object):
    def applySubstitutions(self, replacements, text):
        """
        :type replacements: List[List[str]]
        :type text: str
        :rtype: str
        """
        lookup = {k:v for k, v in replacements}
        memo = {}
        def replace(s):
            if s not in memo:
                result = []
                i = 0
                while i < len(s):
                    if s[i] != '%':
                        result.append(s[i])
                        i += 1
                        continue
                    j = next(j for j in xrange(i+1, len(s)) if s[j] == '%')
                    result.append(replace(lookup[s[i+1:j]]))
                    i = j+1
                memo[s] = "".join(result)
            return memo[s]

        return replace(text)
