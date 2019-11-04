# Time:  O(n)
# Space: O(1)

import threading
import collections


class BoundedBlockingQueue(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.__cv = threading.Condition()
        self.__q = collections.deque()
        self.__cap = capacity

    def enqueue(self, element):
        """
        :type element: int
        :rtype: void
        """
        with self.__cv:
            while len(self.__q) == self.__cap:
                self.__cv.wait()
            self.__q.append(element)
            self.__cv.notifyAll()

    def dequeue(self):
        """
        :rtype: int
        """
        with self.__cv:
            while not self.__q:
                self.__cv.wait()
            self.__cv.notifyAll()
            return self.__q.popleft()

    def size(self):
        """
        :rtype: int
        """
        with self.__cv:
            return len(self.__q)
