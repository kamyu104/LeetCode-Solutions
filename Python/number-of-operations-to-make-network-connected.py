# Time:  O(|E| + |V|)
# Space: O(|V|)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[max(x_root, y_root)] = min(x_root, y_root)
        self.count -= 1
        return True


class Solution(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        if len(connections) < n-1:
            return -1
        union_find = UnionFind(n)
        for i, j in connections:
            union_find.union_set(i, j)
        return union_find.count - 1


# Time:  O(|E| + |V|)
# Space: O(|V|)
import collections


class Solution2(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        def dfs(i, lookup):
            if i in lookup:
                return 0
            lookup.add(i)
            if i in G:
                for j in G[i]:
                    dfs(j, lookup)
            return 1

        if len(connections) < n-1:
            return -1
        G = collections.defaultdict(list)
        for i, j in connections:
            G[i].append(j)
            G[j].append(i)
        lookup = set()
        return sum(dfs(i, lookup) for i in xrange(n)) - 1
