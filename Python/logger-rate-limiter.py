# Time:  O(1), amortized
# Space: O(k), k is the max number of printed messages in last 10 seconds

import collections


class Logger(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__dq = collections.deque()
        self.__printed = set()

    def shouldPrintMessage(self, timestamp, message):
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false. The timestamp is in seconds granularity.
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        while self.__dq and self.__dq[0][0] <= timestamp - 10:
            self.__printed.remove(self.__dq.popleft()[1])
        if message in self.__printed:
            return False
        self.__dq.append((timestamp, message))
        self.__printed.add(message)
        return True

    
