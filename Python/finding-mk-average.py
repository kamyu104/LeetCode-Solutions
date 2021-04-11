# Time:  ctor:           O(1)
#        add_element:    O(logn)
#        calc_mkaverage: O(1)
# Space: O(m)

import collections
from sortedcontainers import SortedList


class MKAverage(object):

    def __init__(self, m, k):
        """
        :type m: int
        :type k: int
        """
        self.__m = m
        self.__k = k
        self.__dq = collections.deque()
        self.__sl = SortedList()
        self.__total = self.__first_k = self.__last_k = 0

    def addElement(self, num):
        """
        :type num: int
        :rtype: None
        """
        if len(self.__dq) == self.__m:
            self.__remove(self.__dq.popleft())
        self.__dq.append(num)
        self.__add(num)

    def calculateMKAverage(self):
        """
        :rtype: int
        """
        if len(self.__sl) < self.__m:
            return -1
        return (self.__total-self.__first_k-self.__last_k)//(self.__m-2*self.__k)

    def __add(self, num):
        self.__total += num
        idx = self.__sl.bisect_left(num)
        if idx < self.__k:
            self.__first_k += num
            if len(self.__sl) >= self.__k:
                self.__first_k -= self.__sl[self.__k-1]
        if idx > len(self.__sl)-self.__k:
            self.__last_k += num
            if len(self.__sl) >= self.__k:
                self.__last_k -= self.__sl[-self.__k]
        self.__sl.add(num)

    def __remove(self, num):
        self.__total -= num
        idx = self.__sl.index(num)
        if idx < self.__k:
            self.__first_k -= num
            self.__first_k += self.__sl[self.__k]
        elif idx > (len(self.__sl)-1)-self.__k:
            self.__last_k -= num
            self.__last_k += self.__sl[-1-self.__k]
        self.__sl.remove(num)
