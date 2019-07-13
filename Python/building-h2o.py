# Time:  O(n)
# Space: O(1)

import threading


# TLE
class H2O(object):
    def __init__(self):
        self.__nH = 0
        self.__nO = 0
        self.__cv = threading.Condition()

    def hydrogen(self, releaseHydrogen):
        """
        :type releaseHydrogen: method
        :rtype: void
        """
        with self.__cv:
            while (self.__nH+1) - 2*self.__nO > 2:
                self.__cv.wait()
            self.__nH += 1
            # releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen()
            self.__cv.notifyAll()


    def oxygen(self, releaseOxygen):
        """
        :type releaseOxygen: method
        :rtype: void
        """
        with self.__cv:
            while 2*(self.__nO+1) - self.__nH > 2:
                self.__cv.wait()
            self.__nO += 1
            # releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen()
            self.__cv.notifyAll()
