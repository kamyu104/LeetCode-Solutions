# Time:  O(n)
# Space: O(1)

import threading


class ZeroEvenOdd(object):
    def __init__(self, n):
        self.__n = n
        self.__curr = 0
        self.__cv = threading.Condition()
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in xrange(self.__n):
            with self.__cv:
                while self.__curr % 2 != 0:
                    self.__cv.wait()
                self.__curr += 1
                printNumber(0)
                self.__cv.notifyAll()
        
    def even(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in xrange(2, self.__n+1, 2):
            with self.__cv:
                while self.__curr % 4 != 3:
                    self.__cv.wait()
                self.__curr += 1
                printNumber(i)
                self.__cv.notifyAll()
        
    def odd(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in xrange(1, self.__n+1, 2):
            with self.__cv:
                while self.__curr % 4 != 1:
                    self.__cv.wait()
                self.__curr += 1
                printNumber(i)
                self.__cv.notifyAll()
