# Time:  ctor:          O(1)
#        setCell:       O(logn)
#        unsetCell:     O(logn)
#        largestMatrix: O(logn)
# Space: O(n^3)

import collections
from sortedcontainers import SortedList


# sorted list
class Matrix3D(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__n = n
        self.__matrix = set()
        self.__cnt = collections.defaultdict(int)
        self.__sl = SortedList([0])
        self.__lookup = collections.defaultdict(SortedList)
        self.__lookup[0].add(n-1)

    def setCell(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: None
        """
        if (x, y, z) in self.__matrix:
            return
        self.__matrix.add((x, y, z))
        if self.__cnt[x] or x == self.__n-1:
            self.__lookup[self.__cnt[x]].remove(x)
            if not self.__lookup[self.__cnt[x]]:
                del self.__lookup[self.__cnt[x]]
                self.__sl.remove(self.__cnt[x])
        self.__cnt[x] += 1
        if self.__cnt[x] not in self.__lookup:
            self.__sl.add(self.__cnt[x])
        self.__lookup[self.__cnt[x]].add(x)

    def unsetCell(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: None
        """
        if (x, y, z) not in self.__matrix:
            return
        self.__matrix.remove((x, y, z))
        self.__lookup[self.__cnt[x]].remove(x)
        if not self.__lookup[self.__cnt[x]]:
            del self.__lookup[self.__cnt[x]]
            self.__sl.remove(self.__cnt[x])
        self.__cnt[x] -= 1
        if self.__cnt[x] or x == self.__n-1:
            if self.__cnt[x] not in self.__lookup:
                self.__sl.add(self.__cnt[x])
            self.__lookup[self.__cnt[x]].add(x)

    def largestMatrix(self):
        """
        :rtype: int
        """
        return self.__lookup[self.__sl[-1]][-1]        


# Time:  ctor:          O(1)
#        setCell:       O(logn)
#        unsetCell:     O(logn)
#        largestMatrix: O(logn) on average
# Space: O(n^3)
import collections
import heapq


# heap
class Matrix3D_2(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__matrix = {}
        self.__cnt = collections.defaultdict(int)
        self.__max_heap = [(0, -(n-1))]

    def setCell(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: None
        """
        if (x, y, z) in self.__matrix:
            return
        self.__matrix[x, y, z] = 1
        self.__cnt[x] += 1
        heapq.heappush(self.__max_heap, (-self.__cnt[x], -x))

    def unsetCell(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: None
        """
        if (x, y, z) not in self.__matrix:
            return
        del self.__matrix[x, y, z]
        self.__cnt[x] -= 1
        heapq.heappush(self.__max_heap, (-self.__cnt[x], -x))

    def largestMatrix(self):
        """
        :rtype: int
        """
        while self.__max_heap and -self.__max_heap[0][0] != self.__cnt[-self.__max_heap[0][1]]:
            heapq.heappop(self.__max_heap)
        return -self.__max_heap[0][1]
