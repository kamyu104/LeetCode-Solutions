# Time:  O(c + n + q), n = len(connections)
# Space: O(c + n)

# dfs, flood fill, sort
class Solution(object):
    def processQueries(self, c, connections, queries):
        """
        :type c: int
        :type connections: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def iter_dfs(i):
            stk = [i]
            while stk:
                u = stk.pop()
                if lookup[u] != -1:
                    continue
                lookup[u] = i
                for v in reversed(adj[u]):
                    stk.append(v)
    
        adj = [[] for _ in xrange(c)]
        for u, v in connections:
            adj[u-1].append(v-1)
            adj[v-1].append(u-1)
        lookup = [-1]*c
        for i in xrange(c):
            iter_dfs(i)
        groups = [[] for _ in xrange(c)]
        for i in reversed(xrange(c)):
            groups[lookup[i]].append(i)
        result = []
        online = [True]*c
        for t, x in queries:
            x -= 1
            if t == 1:
                if online[x]:
                    result.append(x+1)
                    continue
                while groups[lookup[x]] and not online[groups[lookup[x]][-1]]:
                    groups[lookup[x]].pop()
                result.append(groups[lookup[x]][-1]+1 if groups[lookup[x]] else -1)
            else:
                online[x] = False
        return result
