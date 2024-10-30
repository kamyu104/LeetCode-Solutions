# Time:  O(n)
# Space: O(n)

# iterative dfs, hash table
class Solution(object):
    def findSubtreeSizes(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: List[int]
        """
        def iter_dfs():
            lookup = [[] for _ in xrange(26)]
            result = [1]*len(parent)
            stk = [(1, 0)]
            while stk:
                step, u = stk.pop()
                if step == 1:
                    lookup[ord(s[u])-ord('a')].append(u)
                    stk.append((2, u))
                    for v in reversed(adj[u]):
                        stk.append((1, v))
                elif step == 2:
                    for v in adj[u]:
                        result[lookup[ord(s[v])-ord('a')][-1] if lookup[ord(s[v])-ord('a')] else u] += result[v]
                    lookup[ord(s[u])-ord('a')].pop()
            return result
        
        adj = [[] for _ in xrange(len(parent))]
        for v, u in enumerate(parent):
            if u != -1:
                adj[u].append(v)
        return iter_dfs()


# Time:  O(n)
# Space: O(n)
# dfs, hash table
class Solution2(object):
    def findSubtreeSizes(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: List[int]
        """
        def dfs(u):
            lookup[ord(s[u])-ord('a')].append(u)
            for v in adj[u]:
                dfs(v)
                result[lookup[ord(s[v])-ord('a')][-1] if lookup[ord(s[v])-ord('a')] else u] += result[v]
            lookup[ord(s[u])-ord('a')].pop()
        
        adj = [[] for _ in xrange(len(parent))]
        for v, u in enumerate(parent):
            if u != -1:
                adj[u].append(v)
        lookup = [[] for _ in xrange(26)]
        result = [1]*len(parent)
        dfs(0)
        return result
