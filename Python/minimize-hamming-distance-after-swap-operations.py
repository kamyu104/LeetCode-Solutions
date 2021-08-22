# Time:  O(n)
# Space: O(n)

class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        """
        :type source: List[int]
        :type target: List[int]
        :type allowedSwaps: List[List[int]]
        :rtype: int
        """
        def iter_flood_fill(adj, node, lookup, idxs):
            stk = [node]
            while stk:
                node = stk.pop()
                if node in lookup:
                    continue
                lookup.add(node)
                idxs.append(node)
                for child in adj[node]:
                    stk.append(child)

        adj = [set() for i in xrange(len(source))]
        for i, j in allowedSwaps:
            adj[i].add(j)
            adj[j].add(i)
        result = 0
        lookup = set()
        for i in xrange(len(source)):
            if i in lookup:
                continue
            idxs = []
            iter_flood_fill(adj, i, lookup, idxs)
            source_cnt = collections.Counter([source[i] for i in idxs])
            target_cnt = collections.Counter([target[i] for i in idxs])
            diff = source_cnt-target_cnt
            result += sum(diff.itervalues())
        return result


# Time:  O(n * α(n)) ~= O(n)
# Space: O(n)
import collections


class UnionFind(object):  # Time: O(n * α(n)), Space: O(n)
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
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        if self.rank[x_root] < self.rank[y_root]:  # union by rank
            self.set[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.set[y_root] = x_root
        else:
            self.set[y_root] = x_root
            self.rank[x_root] += 1
        return True


class Solution2(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        """
        :type source: List[int]
        :type target: List[int]
        :type allowedSwaps: List[List[int]]
        :rtype: int
        """
        uf = UnionFind(len(source))
        for x, y in allowedSwaps: 
            uf.union_set(x, y)
        groups = collections.defaultdict(set)
        for i in xrange(len(source)):
            groups[uf.find_set(i)].add(i)
        result = 0
        for idxs in groups.itervalues():
            source_cnt = collections.Counter([source[i] for i in idxs])
            target_cnt = collections.Counter([target[i] for i in idxs])
            diff = source_cnt-target_cnt
            result += sum(diff.itervalues())
        return result
