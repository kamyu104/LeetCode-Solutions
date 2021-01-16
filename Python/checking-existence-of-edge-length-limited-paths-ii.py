# Time:  ctor:  O(mlogm + m * α(n) * logm) ~= O(mlogm)
#        query: O(logm + α(n) * logm) ~= O(logm)
# Space: O(n + m * α(n) + m) ~= O(n + m)

import collections
import sortedcontainers
import bisect


class SnapshotArray(object):

    def __init__(self, length):
        """
        :type length: int
        """
        self.__snaps = collections.defaultdict(lambda:sortedcontainers.SortedList([(0, 0)]))


    def set(self, index, val, snap_id):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        i = self.__snaps[index].bisect_left((snap_id, float("-inf")))
        if i != len(self.__snaps[index]) and self.__snaps[index][i][0] == snap_id:
            self.__snaps[index].remove(self.__snaps[index][i])
        self.__snaps[index].add((snap_id, val))


    def get(self, index, snap_id):
        """
        :type index: int
        :type snap_id: int
        :rtype: int
        """
        i = self.__snaps[index].bisect_left((snap_id+1, float("-inf"))) - 1
        return self.__snaps[index][i][1]   
 

class UnionFind(object):  # Time: (n * α(n)), Space: O(n)
    def __init__(self, n):
        self.snap_id = 0
        self.set = SnapshotArray(n)
        for i in xrange(n):
            self.set.set(i, i, self.snap_id)
        self.rank = SnapshotArray(n)

    def find_set(self, x, snap_id):
        stk = []
        while self.set.get(x, snap_id) != x:  # path compression
            stk.append(x)
            x = self.set.get(x, snap_id)
        while stk:
            self.set.set(stk.pop(), x, snap_id)
        return x

    def union_set(self, x, y):
        x_root = self.find_set(x, self.snap_id)
        y_root = self.find_set(y, self.snap_id)
        if x_root == y_root:
            return False
        if self.rank.get(x_root, self.snap_id) < self.rank.get(y_root, self.snap_id):  # union by rank
            self.set.set(x_root, y_root, self.snap_id)
        elif self.rank.get(x_root, self.snap_id) > self.rank.get(y_root, self.snap_id):
            self.set.set(y_root, x_root, self.snap_id)
        else:
            self.set.set(y_root, x_root, self.snap_id)
            self.rank.set(x_root, self.rank.get(x_root, self.snap_id)+1, self.snap_id)
        return True

    def snap(self):
        self.snap_id += 1


class DistanceLimitedPathsExist(object):

    def __init__(self, n, edgeList):
        """
        :type n: int
        :type edgeList: List[List[int]]
        """
        edgeList.sort(key = lambda x:x[2])
        self.__uf = UnionFind(n)
        self.__weights = []
        for index, (i, j, weight) in enumerate(edgeList):
            if not self.__uf.union_set(i, j):
                continue
            self.__uf.snap()
            self.__weights.append(weight)  

    def query(self, p, q, limit):
        """
        :type p: int
        :type q: int
        :type limit: int
        :rtype: bool
        """
        snap_id = bisect.bisect_left(self.__weights, limit)-1
        if snap_id == -1:
            return False
        return self.__uf.find_set(p, snap_id) == self.__uf.find_set(q, snap_id)
