# Time:  push: O(logn)
#        pop:  O(1), amortized
#        popAtStack: O(logn)
# Space: O(n * c)

import heapq


class DinnerPlates(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.__stks = []
        self.__c = capacity
        self.__min_heap = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if self.__min_heap:
            l = heapq.heappop(self.__min_heap)
            if l < len(self.__stks):
                self.__stks[l].append(val)
                return
            self.__min_heap = []  # nothing is valid in min heap
        if not self.__stks or len(self.__stks[-1]) == self.__c:
            self.__stks.append([])
        self.__stks[-1].append(val)

    def pop(self):
        """
        :rtype: int
        """
        while self.__stks and not self.__stks[-1]:
            self.__stks.pop()
        if not self.__stks:
            return -1
        return self.__stks[-1].pop()

    def popAtStack(self, index):
        """
        :type index: int
        :rtype: int
        """
        if index >= len(self.__stks) or not self.__stks[index]:
            return -1
        heapq.heappush(self.__min_heap, index)
        return self.__stks[index].pop()
