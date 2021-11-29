# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """
        meetings.sort(key=lambda x: x[2])
        result = {0, firstPerson}
        adj = collections.defaultdict(list)
        for i, (x, y, _) in enumerate(meetings):
            adj[x].append(y)
            adj[y].append(x)
            if i+1 != len(meetings) and meetings[i+1][2] == meetings[i][2]:
                continue
            q = [i for i in adj.iterkeys() if i in result]
            while q:
                new_q = []
                for u in q:
                    for v in adj[u]:
                        if v in result:
                            continue
                        result.add(v)
                        new_q.append(v)
                q = new_q
            adj = collections.defaultdict(list)
        return list(result)


# Time:  O(nlogn)
# Space: O(n)
import collections


class Solution2(object):
    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """
        meetings.sort(key=lambda x: x[2])
        result = {0, firstPerson}
        adj = collections.defaultdict(list)
        for i, (x, y, _) in enumerate(meetings):
            adj[x].append(y)
            adj[y].append(x)
            if i+1 != len(meetings) and meetings[i+1][2] == meetings[i][2]:
                continue
            stk = [i for i in adj.iterkeys() if i in result]
            while stk:
                u = stk.pop()
                for v in adj[u]:
                    if v in result:
                        continue
                    result.add(v)
                    stk.append(v)
            adj = collections.defaultdict(list)
        return list(result)


# Time:  O(nlogn)
# Space: O(n)
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

    def reset(self, x):
        self.set[x] = x
        self.rank[x] = 0


class Solution3(object):
    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """
        meetings.sort(key=lambda x: x[2])
        uf = UnionFind(n)
        uf.union_set(0, firstPerson)
        group = set()
        for i, (x, y, _) in enumerate(meetings):
            group.add(x)
            group.add(y)
            uf.union_set(x, y)
            if i+1 != len(meetings) and meetings[i+1][2] == meetings[i][2]:
                continue
            while group:
                x = group.pop()
                if uf.find_set(x) != uf.find_set(0):
                    uf.reset(x)
        return [i for i in xrange(n) if uf.find_set(i) == uf.find_set(0)]
