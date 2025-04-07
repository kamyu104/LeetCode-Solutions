# Time:  ctor:          O(1)
#        addPacket:     O(logn)
#        forwardPacket: O(logn)
#        getCount:      O(logn)
# Space: O(n)

import collections
from sortedcontainers import SortedList


# queue, sorted list
class Router(object):

    def __init__(self, memoryLimit):
        """
        :type memoryLimit: int
        """
        self.__size = memoryLimit
        self.__q = collections.deque()
        self.__lookup = collections.defaultdict(SortedList)


    def addPacket(self, source, destination, timestamp):
        """
        :type source: int
        :type destination: int
        :type timestamp: int
        :rtype: bool
        """
        if (timestamp, source) in self.__lookup[destination]:
            return False
        self.__lookup[destination].add((timestamp, source))
        if len(self.__q) == self.__size:
            s, d, t = self.__q.popleft()
            self.__lookup[d].remove((t, s))
        self.__q.append((source, destination, timestamp))
        return True

    def forwardPacket(self):
        """
        :rtype: List[int]
        """
        if not self.__q:
            return []
        s, d, t = self.__q.popleft()
        self.__lookup[d].remove((t, s))
        return [s, d, t]

    def getCount(self, destination, startTime, endTime):
        """
        :type destination: int
        :type startTime: int
        :type endTime: int
        :rtype: int
        """
        return self.__lookup[destination].bisect_left((endTime+1, 0))-self.__lookup[destination].bisect_left((startTime, 0))
