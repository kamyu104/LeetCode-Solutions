# Time:  cotr:      O(1)
#        push:      O(1)
#        pop:       O(1)
#        increment: O(1)
# Space: O(n)

class CustomStack(object):

    def __init__(self, maxSize):
        """
        :type maxSize: int
        """
        self.__max_size = maxSize
        self.__stk = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if len(self.__stk) == self.__max_size:
            return
        self.__stk.append([x, 0])

    def pop(self):
        """
        :rtype: int
        """
        if not self.__stk:
            return -1
        x, inc = self.__stk.pop()
        if self.__stk:
            self.__stk[-1][1] += inc
        return x + inc

    def increment(self, k, val):
        """
        :type k: int
        :type val: int
        :rtype: None
        """
        i = min(len(self.__stk), k)-1
        if i >= 0:
            self.__stk[i][1] += val
