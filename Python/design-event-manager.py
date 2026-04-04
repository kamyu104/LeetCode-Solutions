# Time:  ctor:           O(n)
#        updatePriority: O(logn), amortized
#        pollHightest:   O(logn), amortized
# Space: O(n)

import heapq


# heap, hash table
class EventManager(object):

    def __init__(self, events):
        """
        :type events: List[List[int]]
        """
        self.__lookup = {}
        self.__max_heap = []
        for i, p in events:
            self.__lookup[i] = p
            self.__max_heap.append((-p, i))
        heapq.heapify(self.__max_heap)

    def updatePriority(self, eventId, newPriority):
        """
        :type eventId: int
        :type newPriority: int
        :rtype: None
        """
        self.__lookup[eventId] = newPriority
        heapq.heappush(self.__max_heap, (-newPriority, eventId))
        if len(self.__max_heap) > 2*len(self.__lookup):
            self.__rebuild()
        
    def pollHighest(self):
        """
        :rtype: int
        """
        while self.__max_heap:
            p, i = heapq.heappop(self.__max_heap)
            if i in self.__lookup and self.__lookup[i] == -p:
                del self.__lookup[i]
                return i
        return -1

    def __rebuild(self):
        lookup = {}
        max_heap = []
        while self.__max_heap:
            p, i = heapq.heappop(self.__max_heap)
            if i in self.__lookup and self.__lookup[i] == -p:
                del self.__lookup[i]
                lookup[i] = -p
                heapq.heappush(max_heap, (p, i))
        self.__lookup, self.__max_heap = lookup, max_heap


# Time:  ctor:           O(nlogn)
#        updatePriority: O(logn)
#        pollHightest:   O(logn)
# Space: O(n)
from sortedcontainers import SortedList


# sorted list, hash table
class EventManager2(object):

    def __init__(self, events):
        """
        :type events: List[List[int]]
        """
        self.__lookup = {}
        self.__sl = SortedList()
        for i, p in events:
            self.__lookup[i] = p
            self.__sl.add((p, -i))

    def updatePriority(self, eventId, newPriority):
        """
        :type eventId: int
        :type newPriority: int
        :rtype: None
        """
        self.__sl.remove((self.__lookup[eventId], -eventId))
        self.__lookup[eventId] = newPriority
        self.__sl.add((newPriority, -eventId))  

    def pollHighest(self):
        """
        :rtype: int
        """
        if not self.__sl:
            return -1
        result = -self.__sl.pop()[1]
        self.__lookup.pop(result)
        return result
