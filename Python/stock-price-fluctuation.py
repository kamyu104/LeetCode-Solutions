# Time:  ctor:    O(1)
#        update:  O(logn)
#        current: O(1)
#        max:     O(1)
#        min:     O(1)
# Space: O(n)

from sortedcontainers import SortedList


class StockPrice(object):

    def __init__(self):
        self.__curr = 0
        self.__lookup = {}
        self.__sl_by_price = SortedList()

    def update(self, timestamp, price):
        """
        :type timestamp: int
        :type price: int
        :rtype: None
        """
        if timestamp > self.__curr:
            self.__curr = timestamp
        if timestamp in self.__lookup:
            self.__sl_by_price.remove(self.__lookup[timestamp])
        self.__lookup[timestamp] = price
        self.__sl_by_price.add(price)

    def current(self):
        """
        :rtype: int
        """
        return self.__lookup[self.__curr]

    def maximum(self):
        """
        :rtype: int
        """
        return next(reversed(self.__sl_by_price))

    def minimum(self):
        """
        :rtype: int
        """
        return next(iter(self.__sl_by_price))


# Time:  ctor:    O(1)
#        update:  O(logn)
#        current: O(1)
#        max:     O(logn) on average
#        min:     O(logn) on average
# Space: O(n)
import heapq


class StockPrice2(object):

    def __init__(self):
        self.__curr = 0
        self.__lookup = {}
        self.__min_heap = []
        self.__max_heap = []

    def update(self, timestamp, price):
        """
        :type timestamp: int
        :type price: int
        :rtype: None
        """
        def full_delete(heap, sign):  # Time: O(n), Space: O(n)
            heap[:] = [x for x in set(heap) if sign*x[0] == self.__lookup[x[1]]]
            heapq.heapify(heap)

        if timestamp > self.__curr:
            self.__curr = timestamp
        self.__lookup[timestamp] = price
        heapq.heappush(self.__min_heap, (price, timestamp))
        heapq.heappush(self.__max_heap, (-price, timestamp))
        if len(self.__min_heap) > 2*len(self.__lookup):  # avoid too much expired or duplicated data
            full_delete(self.__min_heap, 1)
            full_delete(self.__max_heap, -1)

    def current(self):
        """
        :rtype: int
        """
        return self.__lookup[self.__curr]

    def maximum(self):
        """
        :rtype: int
        """
        while self.__max_heap and self.__lookup[self.__max_heap[0][1]] != -self.__max_heap[0][0]:  # lazy delete
            heapq.heappop(self.__max_heap)
        return -self.__max_heap[0][0]

    def minimum(self):
        """
        :rtype: int
        """
        while self.__min_heap and self.__lookup[self.__min_heap[0][1]] != self.__min_heap[0][0]:  # lazy delete
            heapq.heappop(self.__min_heap)
        return self.__min_heap[0][0]
