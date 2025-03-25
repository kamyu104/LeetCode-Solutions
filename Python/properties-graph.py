# Time:  O(n^2 * m)
# Space: O(n)

# graph, flood fill, bfs
class Solution(object):
    def numberOfComponents(self, properties, k):
        """
        :type properties: List[List[int]]
        :type k: int
        :rtype: int
        """
        def bfs(u):
            q = [u]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if lookup[v]:
                            continue
                        lookup[v] = True
                        new_q.append(v)
                q = new_q

        p_set = [set(p) for p in properties]
        adj = [[] for _ in xrange(len(properties))]
        for i in xrange(len(p_set)):
            for j in xrange(i+1, len(p_set)):
                if sum(x in p_set[j] for x in p_set[i]) >= k:
                    adj[i].append(j)
                    adj[j].append(i)
        lookup = [False]*len(properties)
        result = 0
        for i in xrange(len(properties)):
            if lookup[i]:
                continue
            bfs(i)
            result += 1
        return result


# Time:  O(n^2 * m)
# Space: O(n)
# graph, union find
class Solution2(object):
    def numberOfComponents(self, properties, k):
        """
        :type properties: List[List[int]]
        :type k: int
        :rtype: int
        """
        class UnionFind(object):  # Time: O(n * alpha(n)), Space: O(n)
            def __init__(self, n):
                self.set = range(n)
                self.rank = [0]*n

            def find_set(self, x):
                stk = []
                while self.set[x] != x:  # path compression
                    stk.append(x)
                    x = self.set[x]
                while stk:
                    self.set[stk.pop()] = x
                return x

            def union_set(self, x, y):
                x, y = self.find_set(x), self.find_set(y)
                if x == y:
                    return False
                if self.rank[x] > self.rank[y]:  # union by rank
                    x, y = y, x
                self.set[x] = self.set[y]
                if self.rank[x] == self.rank[y]:
                    self.rank[y] += 1
                return True
    
        p_set = [set(p) for p in properties]
        uf = UnionFind(len(properties))
        return len(properties)-sum(sum(x in p_set[j] for x in p_set[i]) >= k and uf.union_set(i, j) for i in xrange(len(p_set)) for j in xrange(i+1, len(p_set)))
