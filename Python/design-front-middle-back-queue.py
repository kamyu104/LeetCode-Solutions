# Time:  O(1)
# Space: O(n)

import collections


class FrontMiddleBackQueue(object):

    def __init__(self):
        self.__left, self.__right = collections.deque(), collections.deque()   

    def pushFront(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.__left.appendleft(val)
        self.__balance()        

    def pushMiddle(self, val):
        """
        :type val: int
        :rtype: None
        """
        if len(self.__left) > len(self.__right):
            self.__right.appendleft(self.__left.pop())
        self.__left.append(val)

    def pushBack(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.__right.append(val)
        self.__balance()

    def popFront(self):
        """
        :rtype: int
        """
        val = (self.__left or collections.deque([-1])).popleft()
        self.__balance()
        return val

    def popMiddle(self):
        """
        :rtype: int
        """
        val = (self.__left or [-1]).pop()
        self.__balance()
        return val

    def popBack(self):
        """
        :rtype: int
        """
        val = (self.__right or self.__left or [-1]).pop()
        self.__balance()
        return val

    def __balance(self):
        if len(self.__left) > len(self.__right)+1:
            self.__right.appendleft(self.__left.pop())
        elif len(self.__left) < len(self.__right):
            self.__left.append(self.__right.popleft())
